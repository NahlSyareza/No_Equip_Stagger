namespace Hooks {
    class OnEquip {
    public:
        static void Install() {
            auto& trampoline = SKSE::GetTrampoline();
            REL::Relocation<uintptr_t> equipObjectHook{RELOCATION_ID(37938, 38894), OFFSET(0xE5, 0x170)};
            REL::Relocation<uintptr_t> equipImplHook{RELOCATION_ID(37937, 38893), 0xBC};

            _Equip = trampoline.write_call<5>(equipObjectHook.address(), Equip);
            _Equip = trampoline.write_call<5>(equipImplHook.address(), Equip);
        }

    private:
        static void Equip(RE::ActorEquipManager* manager, RE::Actor* actor, RE::TESBoundObject* object, const RE::ObjectEquipParams& objectEquipParams);
        static inline REL::Relocation<decltype(Equip)> _Equip;
    };

    static void Install() {
        SKSE::AllocTrampoline(14);
        OnEquip::Install();
    }
}