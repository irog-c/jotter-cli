#include <fstream>
#include <exception>
#include <filesystem>

#include <fmt/core.h>
#include <nlohmann/json.hpp>

#include <jotter.hpp>

static constexpr auto default_notes_directory = "/jotter";
static constexpr auto default_notes_location = "/jotter/notes.txt";
static constexpr auto config_location = "/jotter-config.json";

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
        static auto home_location = std::filesystem::path(getenv("HOME")).string();
        return home_location;
    }

    void record_note(std::string_view note, const config& cfg)
    {
        auto home = get_home_location();
        auto directory = home + default_notes_directory;
        auto notes_file = home + default_notes_location;

        try
        {
            if(!std::filesystem::exists(directory))
            {
                std::filesystem::create_directory(directory);
                fmt::println("Directory created: {}", directory);
            }
        }
        catch (const std::exception& e)
        {
            throw std::runtime_error(fmt::format("Error creating directory {}", directory));
        }

        auto file = std::fstream(notes_file, std::fstream::in | std::fstream::out | std::fstream::app);
        if(!file.is_open())
        {
            throw std::runtime_error(fmt::format("Could not open file {}", notes_file));
        }

        file << fmt::format("{}\n", note);
        file.close();
    }

    [[nodiscard]] config get_config()
    {
        auto config_file = get_home_location() + config_location;
        auto file = std::ifstream(config_file);
        if(!file.is_open())
        {
            fmt::println("b");
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
