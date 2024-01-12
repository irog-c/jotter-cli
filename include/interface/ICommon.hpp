#pragma once

#define CXXOPTS_USE_UNICODE 1

#include <string>
#include "IFileSystem.hpp"
#include "IEnvironment.hpp"

namespace Jotter
{
    using epoch = unsigned long long;

    class ICommon
    {
       public:
        virtual ~ICommon() = default;

        [[nodiscard]] virtual std::string getHomeLocation() const = 0;

        [[nodiscard]] virtual epoch getEpochTime() const = 0;

        virtual void createFileIfNonexistent(std::string_view file_path, std::string_view file_contents) const = 0;
    };
}  // namespace Jotter
