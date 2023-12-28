#include <config.hpp>
#include <common.hpp>

#include <fmt/core.h>
#include <nlohmann/json.hpp>

#include <fstream>
#include <filesystem>

namespace jotter
{
    inline static config get_default_config()
    {
        static auto default_notes_location = get_home_location() + ".config/jotter/notes.json";
        return {
            .notes_location = default_notes_location,
            .with_timestamp = false,
        };
    }

    [[nodiscard]] config get_config()
    {
        static constexpr auto config_location = ".config/jotter/jotter-config.json";
        auto config_path                      = get_home_location() + config_location;
        create_file_if_nonexistent(config_path, "{}\n");

        auto file = std::ifstream(config_path);
        if(not file.is_open()) throw std::runtime_error(fmt::format("Could not open config file {}", config_path));

        nlohmann::json config_json;
        file >> config_json;

        auto default_config = get_default_config();
        return {
            .notes_location = (config_json.contains("notesLocation") and config_json["notesLocation"].is_string()
                                   ? std::string(config_json["notesLocation"])
                                   : default_config.notes_location),
            .with_timestamp = (config_json.contains("withTimestamp") and config_json["withTimestamp"].is_boolean()
                                   ? bool(config_json["withTimestamp"])
                                   : default_config.with_timestamp),
        };
    }
}  // namespace jotter
