#pragma once

#include <nlohmann/json.hpp>

#include <string>
#include <string>

namespace jotter
{
    struct fields
    {
        std::string language;
        std::string notes_location;
    };

    class Config
    {
       private:
        static fields default_config_;
        nlohmann::json config_json_;

       public:
        Config();

        [[nodiscard]] std::string get_language();
        [[nodiscard]] std::string get_notes_location();
    };

    [[nodiscard]] fields get_config();
}  // namespace jotter
