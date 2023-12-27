#include <note_manager.hpp>
#include <config.hpp>

#include <nlohmann/json.hpp>
#include <fmt/core.h>
#include <fmt/chrono.h>

#include <fstream>
#include <iostream>

namespace jotter
{
    static note_entry create_entry(std::string_view note)
    {
        return {
            .note_text  = note,
            .epoch_time = get_epoch_time(),
        };
    }

    static void write_entry_to_file(const note_entry& entry, auto& file)
    {
        nlohmann::json json_data;
        file >> json_data;

        if(not json_data.contains("entries")) json_data["entries"] = nlohmann::json::array();

        auto entry_object          = nlohmann::json::object();
        entry_object["note_text"]  = entry.note_text;
        entry_object["epoch_time"] = entry.epoch_time;
        json_data["entries"].push_back(entry_object);

        file.seekp(0);
        file << json_data.dump(4) << '\n';
    }

    void record_note(std::string_view note, const config& cfg)
    {
        const auto& notes_path = cfg.notes_location;
        create_file_if_nonexistent(notes_path, "{}\n");

        auto file = std::fstream(notes_path, std::fstream::in | std::fstream::out);
        if(not file.is_open()) throw std::runtime_error(fmt::format("Could not open file {} for writing.", notes_path));

        auto entry = create_entry(note);
        write_entry_to_file(entry, file);
    }

    void get_notes(const config& cfg)
    {
        const auto& notes_path = cfg.notes_location;
        auto file              = std::fstream(notes_path, std::fstream::in);
        if(not file.is_open())
        {
            fmt::println("No notes recorded.");
            return;
        }

        nlohmann::json json_data;
        file >> json_data;

        if(not json_data.contains("entries")) return;

        for(const auto& entry: json_data["entries"])
        {
            if(cfg.with_timestamp)
            {
                fmt::println(
                    "[{}] {}",
                    std::chrono::system_clock::time_point(std::chrono::milliseconds(epoch_time_t(entry["epoch_time"]))),
                    std::string(entry["note_text"]));
            }
            else
                fmt::println("{}", std::string(entry["note_text"]));
        }
    }
}  // namespace jotter
