#include <config.hpp>
#include <common.hpp>

#include <fmt/core.h>
#include <nlohmann/json.hpp>

#include <fstream>
#include <filesystem>

namespace jotter
{
    inline static config get_default_config() noexcept
    {
        static constexpr auto default_notes_location = "/jotter/notes.txt";
        return {.notes_location = default_notes_location};
    }

    static auto create_config(std::string_view config_path)
    {
        std::filesystem::create_directories(std::filesystem::path(config_path).parent_path());
        std::ofstream file(config_path);
        if(not file.is_open())
        {
            throw std::runtime_error(fmt::format("Could not create config file {}", config_path));
        }

        file << "{}\n";
        file.close();
    }

    [[nodiscard]] config get_config()
    {
        static constexpr auto config_location = ".config/jotter/jotter-config.json";
        auto config_path                      = get_home_location() + config_location;
        if(not std::filesystem::exists(config_path))
        {
            create_config(config_path);
        }

        auto file = std::ifstream(config_path);
        if(not file.is_open())
        {
            throw std::runtime_error(fmt::format("Could not open config file {}", config_path));
        }

        nlohmann::json config_json;
        file >> config_json;
        file.close();

        auto default_config = get_default_config();
        return {.notes_location = (config_json.contains("notesLocation") and config_json["notesLocation"].is_string()
                                       ? std::string(config_json["notesLocation"])
                                       : default_config.notes_location)};
    }
}  // namespace jotter
