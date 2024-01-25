#pragma once

#include "interface/IEnvironment.hpp"

namespace Jotter
{
    class Environment : public IEnvironment
    {
       private:
#ifdef _WIN32
        [[nodiscard]] std::optional<std::string> getEnvWin(const std::string& name) const
        {
            char* buffer      = nullptr;
            size_t bufferSize = 0;

            if(_dupenv_s(&buffer, &bufferSize, name.c_str()) == 0 && buffer != nullptr)
            {
                std::string envVal{buffer};
                free(buffer);
                return envVal;
            }

            return std::nullopt;
        }
#else
        [[nodiscard]] std::optional<std::string> getEnvNonWin(const std::string& name) const
        {
            auto envVal = std::getenv(name.c_str());

            if(envVal != nullptr)
            {
                return std::string(envVal);
            }

            return std::nullopt;
        }
#endif

       public:
        [[nodiscard]] std::optional<std::string> getEnv(const std::string& name) const override
        {
#ifdef _WIN32
            return getEnvWin(name);
#else
            return getEnvNonWin(name);
#endif
        }
    };
}  // namespace Jotter
