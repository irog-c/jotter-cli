#include <string_view>
#include <fstream>
#include <filesystem>

#include <common.hpp>

namespace jotter
{
    std::string get_home_location()
    {
        static auto home_location = std::filesystem::path(getenv("HOME")).string() + "/";
        return home_location;
    }
}