#include "Common.hpp"
#include <fmt/core.h>
#include <fstream>
#include <filesystem>
#include <string_view>

namespace Jotter
{
    [[nodiscard]] epoch_time_t Common::getEpochTime() const
    {
        return std::chrono::duration_cast<std::chrono::milliseconds>(
                   std::chrono::system_clock::now().time_since_epoch())
            .count();
    }

    [[nodiscard]] std::string Common::getHomeLocation() const
    {
        auto homeDir = environment.getEnv("HOME");
        if (!homeDir.has_value()) {
            throw std::runtime_error("HOME not set!");
        }

        static auto homeLocation = fileSystem.resolvePath(homeDir.value()) + "/";
        return homeLocation;
    }

    void Common::createFileIfNonexistent(std::string_view filePath, std::string_view fileContents) const
    {
        if(not std::filesystem::exists(filePath))
        {
            std::filesystem::create_directories(std::filesystem::path(filePath).parent_path());
            std::ofstream file(std::filesystem::path{filePath});
            if(not file.is_open()) throw std::runtime_error(fmt::format("Could not create file {}", filePath));

            file << fileContents;
        }
    }
}  // namespace Jotter
