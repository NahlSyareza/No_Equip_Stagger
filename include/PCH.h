#pragma once

#include <shared_mutex>

#include "RE/Skyrim.h"
#include "SKSE/SKSE.h"

#ifdef NDEBUG
    #include <spdlog/sinks/basic_file_sink.h>
#else
    #include <spdlog/sinks/msvc_sink.h>
#endif
#include <xbyak/xbyak.h>

#include "ClibUtil/editorID.hpp"
#include "ClibUtil/simpleINI.hpp"
#include "ClibUtil/singleton.hpp"
#include "ClibUtil/string.hpp"

namespace logger = SKSE::log;
namespace string = clib_util::string;
namespace edid = clib_util::editorID;
namespace ini = clib_util::ini;

using namespace std::literals;
using namespace clib_util::string::literals;
using namespace clib_util::singleton;

#define DLLEXPORT __declspec(dllexport)

// #ifdef SKYRIM_AE
#define OFFSET(se, ae) ae
// #else
// #define OFFSET(se, ae) se
// #endif