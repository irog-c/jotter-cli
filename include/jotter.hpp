#pragma once

#include <string_view>
#include <string>

namespace jotter
{
    struct config
    {
        std::string notes_location;
    };

    void record_note(std::string_view, const config&);
    [[nodiscard]] config get_config();
}
