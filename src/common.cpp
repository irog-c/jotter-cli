#include <common.hpp>
#include <fmt/core.h>

#include <fstream>
#include <filesystem>
#include <string_view>

namespace jotter
{
    std::string get_home_location()
    {
        static auto home_location = std::filesystem::path(std::getenv("HOME")).string() + "/";
        return home_location;
    }

    epoch_time_t get_epoch_time()
    {
        return std::chrono::duration_cast<std::chrono::milliseconds>(
                   std::chrono::system_clock::now().time_since_epoch())
            .count();
    }

    void create_file_if_nonexistent(std::string_view file_path, std::string_view file_contents)
    {
        if(not std::filesystem::exists(file_path))
        {
            std::filesystem::create_directories(std::filesystem::path(file_path).parent_path());
            std::ofstream file(std::filesystem::path{ file_path });
            if(not file.is_open()) throw std::runtime_error(fmt::format("Could not create file {}", file_path));

            file << file_contents;
        }
    }
}  // namespace jotter
