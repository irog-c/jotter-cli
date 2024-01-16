#pragma once

#include "interface/IFileSystem.hpp"

#include <gmock/gmock.h>

namespace Jotter
{
    class MockFileSystem : public IFileSystem
    {
       public:
        MOCK_METHOD(std::string, resolvePath, (const std::string& path), (override));
    };
}  // namespace Jotter
