#include <fstream>
#include <exception>

#include <fmt/core.h>
#include <nlohmann/json.hpp>

#include <note_manager.hpp>
#include <config.hpp>
#include <common.hpp>

namespace jotter
{
    void record_note(std::string_view note, const config& cfg)
    {
        const auto home_path = get_home_location();
        auto notes_path = home_path + cfg.notes_location;
        auto file = std::fstream(notes_path, std::fstream::in | std::fstream::out | std::fstream::app);
        if(!file.is_open())
        {
            throw std::runtime_error(fmt::format("Could not open file {}", notes_path));
        }

        file << fmt::format("{}\n", note);
        file.close();
    }
}
