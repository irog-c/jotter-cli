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
            static Entry create(std::string_view);
            void write_to_file(auto&) const;
        };

        Config& cfg_;
        Params& params_;

        static void write_entry_to_file(const Entry& entry, auto& file);

       public:
        Note() = delete;
        Note(Config&, Params&);

        void get() const;
        void record(std::string_view) const;
    };
}  // namespace jotter
