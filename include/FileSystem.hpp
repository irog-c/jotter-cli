#pragma once

#include "interface/IFileSystem.hpp"

namespace Jotter
{
    class FileSystem : public IFileSystem
    {
        std::string resolvePath(const std::string_view &path) override
        {
            return std::filesystem::path(path).string();
        }
    };
}  // namespace Jotter
