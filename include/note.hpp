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
        struct Entry
        {
            std::string_view note_text;
            epoch_time_t epoch_time;
        };

        Config& cfg_;
        Params& params_;

        static Entry create_entry(std::string_view);
        static void write_entry_to_file(const Entry& entry, auto& file);

       public:
        Note() = delete;
        Note(Config&, Params&);

        void get();
        void record(std::string_view);
    };
}  // namespace jotter
