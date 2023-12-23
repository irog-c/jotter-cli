#include <note_manager.hpp>
#include <config.hpp>
#include <common.hpp>

#include <fmt/core.h>
#include <fstream>

namespace jotter
{
    void record_note(std::string_view note, const config& cfg)
    {
        auto notes_path = get_home_location() + cfg.notes_location;
        auto file       = std::fstream(notes_path, std::fstream::in | std::fstream::out | std::fstream::app);
        if(not file.is_open())
        {
            throw std::runtime_error(fmt::format("Could not open file {}", notes_path));
        }

        file << fmt::format("{}\n", note);
        file.close();
    }
}  // namespace jotter
