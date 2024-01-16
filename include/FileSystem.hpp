#pragma once

#include "interface/IFileSystem.hpp"

namespace Jotter
{
    class FileSystem : public IFileSystem
    {
        std::string resolvePath(const std::string& path) override
        {
            return std::filesystem::path(path).string();
        }
    };
}  // namespace Jotter
