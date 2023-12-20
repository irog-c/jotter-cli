#include <config.hpp>
#include <common.hpp>

#include <fmt/core.h>
#include <nlohmann/json.hpp>

#include <fstream>

namespace jotter
{
    static config get_default_config()
    {
        static constexpr auto default_notes_location = "/jotter/notes.txt";        
        return {
            .notes_location = default_notes_location
        };
    }

    [[nodiscard]] config get_config()
    {
        static constexpr auto config_location = "jotter-config.json";
        auto config_file = get_home_location() + config_location;
        auto file = std::ifstream(config_file);
        if(not file.is_open())
        {
            throw std::runtime_error(fmt::format("Could not open config file {}", config_file));
        }

        nlohmann::json config_json;
        file >> config_json;
        auto default_config = get_default_config();
        
        file.close();

        return {
            .notes_location = (config_json.contains("notesLocation") && config_json["notesLocation"].is_string() ? std::string(config_json["notesLocation"]) : default_config.notes_location)
        };
    }
}