#include "Logger.h"
#include "Manager.h"

void OnMessage(SKSE::MessagingInterface::Message* message) {
    if (message->type == SKSE::MessagingInterface::kDataLoaded) {
        // Start
    }

    if (message->type == SKSE::MessagingInterface::kPostLoad) {
        NoEquipStagger::Install();
    }

    if (message->type == SKSE::MessagingInterface::kNewGame || message->type == SKSE::MessagingInterface::kPostLoadGame) {
        // Post-load
    }
}

SKSEPluginLoad(const SKSE::LoadInterface* skse) {
    SetupLog();
    logger::info("Plugin loaded");

    logger::info("Incredibilis blyat");

    logger::info("Forget it bitch bau bau");

    SKSE::Init(skse);

    // auto messaging = SKSE::GetMessagingInterface();
    // messaging->RegisterListener("SKSE", OnMessage);

    auto messaging = SKSE::GetMessagingInterface();
    messaging->RegisterListener("SKSE", OnMessage);

    return true;
}