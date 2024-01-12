#pragma once

#include <string>
#include <optional>

namespace Jotter
{
    class IEnvironment
    {
       public:
        virtual ~IEnvironment()                                                 = default;
        [[nodiscard]] virtual std::optional<std::string> getEnv(const std::string& name) const = 0;
    };
}  // namespace Jotter
