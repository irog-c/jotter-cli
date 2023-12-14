#include <common.hpp>

#include <string_view>
#include <fstream>
#include <filesystem>

namespace jotter
{
    std::string get_home_location()
    {
        static auto home_location = std::filesystem::path(getenv("HOME")).string() + "/";
        return home_location;
    }
}