#pragma once

#include <filesystem>

namespace Jotter
{
    class IFileSystem
    {
       public:
        virtual ~IFileSystem()                                        = default;
        virtual std::string resolvePath(const std::string_view& path) = 0;
    };
}  // namespace Jotter
