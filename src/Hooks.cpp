#include "Hooks.h"

bool isStaggering(RE::Actor* actor) {
    bool stateStaggering = false;
    return actor->GetGraphVariableBool("IsStaggering", stateStaggering) && stateStaggering;
}

// Still don't know how to restrict spell equipping, cuz it doesn't even fire this event
void Hooks::OnEquip::Equip(RE::ActorEquipManager* manager, RE::Actor* actor, RE::TESBoundObject* object, const RE::ObjectEquipParams& objectEquipParams) {
    // Finally! Watchout for AE/SE in PCH.h

    if (actor) {
        if (!actor->IsDead() && isStaggering(actor)) {
            logger::info("Staggered! Cannot equip items!");
            return;
        } else {
            logger::info("Not staggered! Can equip items!");
        }
    }

    return _Equip(manager, actor, object, objectEquipParams);
}