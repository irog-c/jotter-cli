#include <fstream>
#include <exception>

#include <fmt/core.h>
#include <nlohmann/json.hpp>

#include <jotter.hpp>

static constexpr auto file_name = "notes.txt";
static constexpr auto config_file_name = "default-config.json";

namespace jotter
{
    void record_note(std::string_view note) noexcept
    {
        auto file = std::fstream(file_name, std::fstream::in | std::fstream::out | std::fstream::app);
        if(!file.is_open())
        {
            fmt::println("Error! Could not open file {}.", file_name);
            return;
        }

        file << fmt::format("{}\n", note);
        file.close();
    }

    [[nodiscard]] config get_config()
    {
        auto file = std::ifstream(config_file_name);
        if(!file.is_open())
        {
            throw std::runtime_error(fmt::format("Could not open file{}.", config_file_name));
        }

        nlohmann::json config_json;
        file >> config_json;

        return {
            .testval = config_json["testVal"]
        };
    }
}