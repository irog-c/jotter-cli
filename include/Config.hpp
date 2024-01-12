#pragma once

#include <nlohmann/json.hpp>

#include <string>
#include "interface/ICommon.hpp"

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

        explicit Config(ICommon& common);

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
}  // namespace jotter
