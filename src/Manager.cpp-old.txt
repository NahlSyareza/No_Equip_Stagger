#include "Manager.h"

#include "Logger.h"

namespace NoEquipStagger {
    bool isStaggering(RE::Actor* actor) {
        bool stateStaggering = false;
        return actor->GetGraphVariableBool("IsStaggering", stateStaggering) && stateStaggering;
    }

    namespace Equip {
        struct DoEquip {
            static void thunk(RE::ActorEquipManager* manager, RE::Actor* actor, RE::TESBoundObject* object, const RE::ObjectEquipParams& objectEquipParams) {
                // Finally! Watchout for AE/SE in PCH.h

                if (actor) {
                    if (!actor->IsDead() && isStaggering(actor)) {
                        logger::info("Staggered! Cannot equip items!");
                        return;
                    } else {
                        logger::info("Not staggered! Can equip items!");
                    }
                }

                return func(manager, actor, object, objectEquipParams);
            }

            static inline REL::Relocation<decltype(thunk)> func;
        };

        void Install() {
            logger::info("Trying to download!");

            std::array targets{
                std::make_pair(RELOCATION_ID(37938, 38894), OFFSET(0xE5, 0x170)),  // ActorEquipManager::EquipObject
                std::make_pair(RELOCATION_ID(37937, 38893), 0xBC),                 // ActorEquipManager::EquipImpl?
            };

            for (const auto& [id, offset] : targets) {
                REL::Relocation<std::uintptr_t> target{id, offset};
                stl::write_thunk_call<DoEquip>(target.address());
            }
        }
    }

    void Install() { Equip::Install(); }
}