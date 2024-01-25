#pragma once

#include "Config.hpp"

namespace Jotter
{
    class ConfigFactory
    {
       public:
        static inline Jotter::Config create()
        {
            auto fileSystem  = std::make_shared<FileSystem>();
            auto environment = std::make_shared<Environment>();
            auto common      = std::make_shared<Common>(fileSystem, environment);
            return Jotter::Config{common};
        };
    };
}  // namespace Jotter
