#pragma once

#include <utility>

#include "interface/ICommon.hpp"

namespace Jotter
{
    class Common : public ICommon
    {
       protected:
        std::shared_ptr<IFileSystem> fileSystem;
        std::shared_ptr<IEnvironment> environment;

       public:
        Common() = delete;

        Common(std::shared_ptr<IFileSystem> iFileSystem, std::shared_ptr<IEnvironment> iEnvironment)
            : fileSystem(std::move(iFileSystem)), environment(std::move(iEnvironment))
        {
        }

        void createFileIfNonexistent(std::string_view filePath, std::string_view fileContents) const override;

        [[nodiscard]] epoch getEpochTime() const override;

        [[nodiscard]] std::string getHomeLocation() const override;
    };
}  // namespace Jotter
