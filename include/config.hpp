#pragma once

#include <string>

namespace jotter
{
    struct config
    {
        std::string notes_location;
    };

    [[nodiscard]] config get_config();
}  // namespace jotter
