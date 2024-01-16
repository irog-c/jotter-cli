#pragma once

#include "Config.hpp"

namespace Jotter
{
    class ConfigFactory
    {
       public:
        static inline Jotter::Config create()
        {
            return Jotter::Config{
                new Common{std::make_shared<FileSystem>(), std::make_shared<Environment>()}
            };
        };
    };
}  // namespace Jotter
