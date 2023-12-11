#include <fstream>

#include <fmt/core.h>
#include <nlohmann/json.hpp>

#include <jotter.hpp>

static constexpr auto file_name = "notes.txt";

namespace jotter
{
    void record_note(std::string_view note) noexcept
    {
        auto file = std::fstream(file_name, std::fstream::in | std::fstream::out | std::fstream::app);
        if(!file)
        {
            fmt::println("Error! Could not open file {}.", file_name);
            return;
        }

        file << fmt::format("{}\n", note);
        file.close();
    }

    config get_config()
    {
         nlohmann::json json_obj = {
        {"example_key", "example_value"}
        };

        fmt::println("{}", json_obj.dump(4));
    }
}