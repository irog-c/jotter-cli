#pragma once

#include <params.hpp>
#include <config.hpp>
#include <common.hpp>

#include <string_view>

namespace jotter
{
    class Note
    {
       private:
        struct note_entry
        {
            std::string_view note_text;
            epoch_time_t epoch_time;
        };

        Config& cfg_;
        Params& params_;

        note_entry create_entry(std::string_view);
        void write_entry_to_file(const note_entry& entry, auto& file);

       public:
        Note() = delete;
        Note(Config&, Params&);

        void get();
        void record(std::string_view);
    };
}  // namespace jotter
