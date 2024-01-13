#pragma once

#include "interface/IEnvironment.hpp"

#include <gmock/gmock.h>

namespace Jotter
{
    class MockEnvironment : public IEnvironment
    {
       public:
        MOCK_CONST_METHOD1(getEnv, std::optional<std::string>(const std::string&));
    };
}  // namespace Jotter
