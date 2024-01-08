#include <note.hpp>
#include <config.hpp>

#include <nlohmann/json.hpp>
#include <fmt/core.h>
#include <fmt/chrono.h>

#include <fstream>

namespace jotter
{
    Note::Entry::Entry(std::string_view note) : note_text(note), epoch_time(get_epoch_time())
    {
    }

    void Note::Entry::write_to_file(auto& file) const
    {
        nlohmann::json json_data;
        file >> json_data;

        if(not json_data.contains("entries")) json_data["entries"] = nlohmann::json::array();

        auto entry_object          = nlohmann::json::object();
        entry_object["note_text"]  = this->note_text;
        entry_object["epoch_time"] = this->epoch_time;
        json_data["entries"].push_back(entry_object);

        file.seekp(0);
        file << json_data.dump() << '\n';
    }

    Note::Note(const Config& cfg, const Params& params) : cfg_(cfg), params_(params)
    {
    }

    void Note::record(std::string_view note) const
    {
        auto notes_path = cfg_.get_notes_location();
        create_file_if_nonexistent(notes_path, "{}\n");

        auto file = std::fstream(notes_path, std::fstream::in | std::fstream::out);
        if(not file.is_open()) throw std::runtime_error(fmt::format("Could not open file {} for writing.", notes_path));

        Note::Entry(note).write_to_file(file);
    }

    void Note::get() const
    {
        auto notes_path = cfg_.get_notes_location();
        auto file       = std::fstream(notes_path, std::fstream::in);
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
            if(params_.get_timestamp())
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
