#pragma once

#include <string>

namespace jotter
{
    struct config
    {
        std::string language;
        std::string notes_location;
        bool with_timestamp;
    };

    [[nodiscard]] config get_config();
}  // namespace jotter
