#include "Note.hpp"
#include "Config.hpp"

#include <nlohmann/json.hpp>
#include <fmt/core.h>
#include <fmt/chrono.h>

#include <fstream>

namespace Jotter
{
    Note::Entry::Entry(std::string_view note, ICommon& common) : entryText(note), creationTime(common.getEpochTime())
    {
    }

    void Note::Entry::writeToFile(auto& file) const
    {
        nlohmann::json jsonData;
        file >> jsonData;

        if(not jsonData.contains("entries")) jsonData["entries"] = nlohmann::json::array();

        auto entryObject          = nlohmann::json::object();
        entryObject["note_text"]  = this->entryText;
        entryObject["epoch_time"] = this->creationTime;
        jsonData["entries"].push_back(entryObject);

        file.seekp(0);
        file << jsonData.dump() << '\n';
    }

    Note::Note(const Config& cfg, const Params& params) : cfg_(cfg), params_(params)
    {
    }

    void Note::record(std::string_view note) const
    {
        auto notesLocation = cfg_.getNotesLocation();
        cfg_.common.createFileIfNonexistent(notesLocation, "{}\n");

        auto file = std::fstream(notesLocation, std::fstream::in | std::fstream::out);
        if(not file.is_open()) throw std::runtime_error(fmt::format("Could not open file {} for writing.", notesLocation));

        Note::Entry(note, cfg_.common).writeToFile(file);
    }

    void Note::get() const
    {
        auto notesLocation = cfg_.getNotesLocation();
        auto file       = std::fstream(notesLocation, std::fstream::in);
        if(not file.is_open())
        {
            fmt::println("No notes recorded.");
            return;
        }

        nlohmann::json jsonData;
        file >> jsonData;

        if(not jsonData.contains("entries")) return;

        for(const auto& entry: jsonData["entries"])
        {
            if(params_.isTimestampRequested())
            {
                fmt::println(
                    "[{}] {}",
                    std::chrono::system_clock::time_point(std::chrono::milliseconds(epoch(entry["epoch_time"]))),
                    std::string(entry["note_text"]));
            }
            else
                fmt::println("{}", std::string(entry["note_text"]));
        }
    }
}  // namespace Jotter
