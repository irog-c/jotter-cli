#pragma once

#include "interface/ICommon.hpp"

namespace Jotter
{
    class Common : public ICommon
    {
       protected:
        std::unique_ptr<IFileSystem> fileSystem;
        std::unique_ptr<IEnvironment> environment;

       public:
        Common() = delete;

        Common(IFileSystem* iFileSystem, IEnvironment* iEnvironment)
            : fileSystem(iFileSystem), environment(iEnvironment)
        {
        }

        void createFileIfNonexistent(std::string_view filePath, std::string_view fileContents) const override;

        [[nodiscard]] epoch getEpochTime() const override;

        [[nodiscard]] std::string getHomeLocation() const override;
    };
}  // namespace Jotter
