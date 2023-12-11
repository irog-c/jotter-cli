#include <fstream>
#include <exception>

#include <fmt/core.h>
#include <nlohmann/json.hpp>

#include <jotter.hpp>

static constexpr auto default_notes_directory = "/jotter";
static constexpr auto default_notes_location = "/jotter/notes.txt";

namespace jotter
{
    static config get_default_config()
    {
        return {
            .notes_location = default_notes_location
        };
    }

    static auto& get_home_location()
    {
        static auto home_location = std::filesystem::path(getenv("HOME")).string() + "/";
        return home_location;
    }

    void record_note(std::string_view note, const config& cfg)
    {
        const auto home_path = get_home_location();
        auto notes_path = home_path + default_notes_location;
        auto file = std::fstream(notes_path, std::fstream::in | std::fstream::out | std::fstream::app);
        if(!file.is_open())
        {
            throw std::runtime_error(fmt::format("Could not open file {}", notes_path));
        }

        file << fmt::format("{}\n", note);
        file.close();
    }

    [[nodiscard]] config get_config()
    {
        static constexpr auto config_location = "/jotter-config.json";
        auto config_file = get_home_location() + config_location;
        auto file = std::ifstream(config_file);
        if(!file.is_open())
        {
            throw std::runtime_error(fmt::format("Could not open file {}", config_file));
        }

        nlohmann::json config_json;
        file >> config_json;
        auto default_config = get_default_config();

        return {
            .notes_location = (config_json.contains("notesLocation") ? std::string(config_json["notesLocation"]) : default_config.notes_location)
        };
    }
}
