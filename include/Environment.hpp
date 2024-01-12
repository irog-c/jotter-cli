#pragma once

#include "interface/IEnvironment.hpp"

namespace Jotter
{
    class Environment : public IEnvironment
    {
        [[nodiscard]] std::optional<std::string> getEnv(const std::string& name) const override
        {
            if(const char* env_var = std::getenv(name.c_str()))
            {
                return std::string(env_var);
            }

            return std::nullopt;
        }
    };
}  // namespace Jotter
