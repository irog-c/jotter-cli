#include "MockEnvironment.hpp"
#include "FileSystem.hpp"
#include "Common.hpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace Jotter
{
    class TestCommon : public ::testing::Test
    {
       protected:
        std::shared_ptr<FileSystem> fileSystem;
        std::shared_ptr<MockEnvironment> environment;
        Jotter::Common common;

       public:
        TestCommon()
            : fileSystem(new FileSystem),
              environment(new MockEnvironment),
              common(fileSystem, environment)
        {
        }
    };

    TEST_F(TestCommon, GetHomeLocationFailure)
    {
        EXPECT_CALL(*environment, getEnv(HOME_VAR)).WillOnce(testing::Return(std::nullopt));
        EXPECT_THROW((void)common.getHomeLocation(), std::runtime_error);
    }

    TEST_F(TestCommon, GetHomeLocationFailureMessage)
    {
        EXPECT_CALL(*environment, getEnv(HOME_VAR)).WillOnce(testing::Return(std::nullopt));

        try
        {
            auto value = common.getHomeLocation();
        }
        catch(const std::runtime_error &err)
        {
            EXPECT_EQ(err.what(), std::string("HOME not set!"));
        }
    }

    TEST_F(TestCommon, GetHomeLocationSuccess)
    {
        std::optional<std::string> homePath = "/home/user";

        EXPECT_CALL(*environment, getEnv(HOME_VAR)).WillOnce(testing::Return(homePath));

        std::string result = common.getHomeLocation();

        EXPECT_EQ(result, homePath.value() + "/");
    }

}  // namespace Jotter
