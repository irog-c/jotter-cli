#pragma once

#include <nlohmann/json.hpp>

#include <string>
#include <string>

namespace jotter
{

    class Config
    {
       private:
        struct Fields
        {
            std::string language;
            std::string notes_location;
        };

       private:
        static Fields default_config_;
        nlohmann::json config_json_;

       public:
        Config();

        [[nodiscard]] inline std::string get_language()
        {
            return (config_json_.contains("language") and config_json_["language"].is_string()
                        ? std::string(config_json_["language"])
                        : default_config_.language);
        }
        [[nodiscard]] inline std::string get_notes_location()
        {
            return (config_json_.contains("notesLocation") and config_json_["notesLocation"].is_string()
                        ? std::string(config_json_["notesLocation"])
                        : default_config_.notes_location);
        }
    };
}  // namespace jotter
