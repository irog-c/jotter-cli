#pragma once

#include <config.hpp>
#include <common.hpp>

#include <string_view>

namespace jotter
{
    struct note_entry
    {
        std::string_view note_text;
        epoch_time_t epoch_time;
    };
    void record_note(std::string_view, const config&);
}  // namespace jotter
