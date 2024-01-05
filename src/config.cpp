#include <config.hpp>
#include <common.hpp>

#include <fmt/core.h>

#include <fstream>

namespace jotter
{
    Config::Fields Config::default_config_ = []() -> Config::Fields {
        auto default_notes_location = get_home_location() + ".config/jotter/notes.json";
        return {
            .language       = "en",
            .notes_location = default_notes_location,
        };
    }();

    Config::Config()
    {
        static constexpr auto config_location = ".config/jotter/jotter-config.json";
        auto config_path                      = get_home_location() + config_location;
        create_file_if_nonexistent(config_path, "{}\n");

        auto file = std::ifstream(config_path);
        if(not file.is_open()) throw std::runtime_error(fmt::format("Could not open config file {}", config_path));

        file >> config_json_;
    }
}  // namespace jotter
