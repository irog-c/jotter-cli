#include <config.hpp>
#include <common.hpp>

#include <fmt/core.h>

#include <fstream>

namespace jotter
{
    inline static fields get_default_config()
    {
        static auto default_notes_location = get_home_location() + ".config/jotter/notes.json";
        return {
            .language       = "en",
            .notes_location = default_notes_location,
        };
    }
    fields Config::default_config_ = get_default_config();

    Config::Config()
    {
        static constexpr auto config_location = ".config/jotter/jotter-config.json";
        auto config_path                      = get_home_location() + config_location;
        create_file_if_nonexistent(config_path, "{}\n");

        auto file = std::ifstream(config_path);
        if(not file.is_open()) throw std::runtime_error(fmt::format("Could not open config file {}", config_path));

        file >> config_json_;
    }

    std::string Config::get_language()
    {
        return (config_json_.contains("language") and config_json_["language"].is_string()
                    ? std::string(config_json_["language"])
                    : default_config_.language);
    }

    std::string Config::get_notes_location()
    {
        return (config_json_.contains("notesLocation") and config_json_["notesLocation"].is_string()
                    ? std::string(config_json_["notesLocation"])
                    : default_config_.notes_location);
    }
}  // namespace jotter
