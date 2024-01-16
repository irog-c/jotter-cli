#include <gtest/gtest.h>
#include "MockFileSystem.hpp"
#include "MockEnvironment.hpp"
#include "Common.hpp"

namespace Jotter
{
    class TestCommonWithMockFileSystem : public ::testing::Test
    {
       protected:
        Jotter::MockFileSystem mockFileSystem;
        Jotter::MockEnvironment environment;
        Jotter::Common common{mockFileSystem, environment};
    };

    TEST_F(TestCommonWithMockFileSystem, ThrowsExceptionWhenResolvePathCalled)
    {
        std::optional<std::string> homePath = "/home/user";
        EXPECT_CALL(environment, getEnv(HOME_VAR)).WillOnce(testing::Return(homePath));
        EXPECT_CALL(mockFileSystem, resolvePath(homePath.value()))
            .WillOnce(testing::Throw(std::filesystem::filesystem_error("filesystem error", std::error_code())));
        EXPECT_THROW((void)common.getHomeLocation(), std::filesystem::filesystem_error);
    }
}  // namespace Jotter
