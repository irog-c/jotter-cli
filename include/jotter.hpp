#pragma once

#include <string_view>

namespace jotter
{
    struct config
    {
        int testval;
    };

    void record_note(std::string_view) noexcept;
    config get_config();
}