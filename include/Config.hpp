#pragma once

#include <nlohmann/json.hpp>

#include <string>
#include "interface/ICommon.hpp"
#include "Common.hpp"
#include "FileSystem.hpp"
#include "Environment.hpp"

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

        explicit Config(ICommon&& common);

       public:
        ICommon& common;

        Config() = delete;

        Config(const Config&) = delete;

        Config& operator=(const Config&) = delete;

        Config(Config&&) = delete;

        static Config& getInstance()
        {
            static Config INSTANCE{
                Common{FileSystem{}, Environment{}}
            };

            return INSTANCE;
        }

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
