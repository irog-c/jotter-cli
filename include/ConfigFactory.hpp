//
// Created by kyryl on 1/13/2024.
//

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
                Jotter::Common{Jotter::FileSystem{}, Jotter::Environment{}}
            };
        };
    };
}  // namespace Jotter
