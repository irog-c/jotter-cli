#pragma once

#include "interface/ICommon.hpp"
#include "Common.hpp"
#include "FileSystem.hpp"
#include "Environment.hpp"

#include <nlohmann/json.hpp>

#include <string>

namespace Jotter
{
    class Config
    {
       private:
        struct Fields
        {
            std::string language;
            std::string notesLocation;
        };

        Fields configFields_;

        nlohmann::json jsonConfig_;

       public:
        ICommon& common;

        Config() = delete;

        explicit Config(ICommon&& common);

        [[nodiscard]] inline std::string getLanguage() const
        {
            return (jsonConfig_.contains("language") and jsonConfig_["language"].is_string()
                        ? std::string(jsonConfig_["language"])
                        : configFields_.language);
        }

        [[nodiscard]] inline std::string getNotesLocation() const
        {
            return (jsonConfig_.contains("notesLocation") and jsonConfig_["notesLocation"].is_string()
                        ? std::string(jsonConfig_["notesLocation"])
                        : configFields_.notesLocation);
        }
    };
}  // namespace Jotter
