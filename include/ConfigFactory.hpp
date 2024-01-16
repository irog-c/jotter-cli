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
                new Common{new FileSystem, new Environment}
            };
        };
    };
}  // namespace Jotter
