#include <note_manager.hpp>
#include <config.hpp>

#include <nlohmann/json.hpp>
#include <fmt/core.h>

#include <fstream>
#include <iostream>

namespace jotter
{
    static note_entry create_entry(std::string_view note)
    {
        return note_entry{
            .note_text  = note,
            .epoch_time = get_epoch_time(),
        };
    }

    static void write_entry_to_json(const note_entry& entry, auto& file)
    {
        nlohmann::json json_data;
        file >> json_data;

        if(not json_data.contains("notes_list")) json_data["notes_list"] = nlohmann::json::array();

        auto entry_object          = nlohmann::json::object();
        entry_object["note_text"]  = entry.note_text;
        entry_object["epoch_time"] = entry.epoch_time;
        json_data["notes_list"].push_back(entry_object);

        file.seekp(0);
        file << json_data.dump(4) << '\n';
    }

    void record_note(std::string_view note, const config& cfg)
    {
        const auto& notes_path = cfg.notes_location;
        create_file_if_nonexistant(notes_path, "{}\n");

        auto file = std::fstream(notes_path, std::fstream::in | std::fstream::out);
        if(not file.is_open()) throw std::runtime_error(fmt::format("Could not open file {}", notes_path));

        auto entry = create_entry(note);
        write_entry_to_json(entry, file);
        file.close();
    }
}  // namespace jotter
