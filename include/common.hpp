#pragma once

#include <string>

namespace jotter
{
    using epoch_time_t = unsigned long long;

    std::string get_home_location();

    epoch_time_t get_epoch_time();

    void create_file_if_nonexistent(std::string_view file_path, std::string_view file_contents = "");
}  // namespace jotter
