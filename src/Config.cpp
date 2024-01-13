#include "interface/ICommon.hpp"
#include "Config.hpp"

#include <fmt/core.h>

#include <fstream>

namespace Jotter
{
    Config::Config(ICommon&& common) : common(common)
    {
        static constexpr auto configLocation  = ".config/jotter/jotter-config.json";
        static constexpr auto notesLocation   = ".config/jotter/notes.json";
        static constexpr auto defaultLanguage = "en";
        auto configPath                       = common.getHomeLocation() + configLocation;
        configFields_.notesLocation           = common.getHomeLocation() + notesLocation;
        configFields_.language                = defaultLanguage;
        common.createFileIfNonexistent(configPath, "{}\n");

        auto file = std::ifstream(configPath);
        if(not file.is_open()) throw std::runtime_error(fmt::format("Could not open config file {}", configPath));

        file >> jsonConfig_;
    }
}  // namespace Jotter
