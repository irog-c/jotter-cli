#pragma once

#include <fmt/core.h>
#include <cxxopts.hpp>

#include <string_view>

namespace jotter
{
    class Params
    {
       private:
        static cxxopts::Options options_;
        cxxopts::ParseResult parsed_options_;
        bool empty_params_;

       public:
        Params() = delete;
        Params(const int argc, const char* argv[], std::string_view language);
        [[nodiscard]] inline bool empty() noexcept
        {
            return empty_params_;
        }

        inline void print_help()
        {
            fmt::println("{}", options_.help());
        }

        [[nodiscard]] inline bool get_help()
        {
            return parsed_options_.count("help") >= 1u;
        }

        [[nodiscard]] bool get_get()
        {
            return parsed_options_.count("get") >= 1u;
        }

        [[nodiscard]] bool get_timestamp()
        {
            return parsed_options_.count("timestamp") >= 1u;
        }

        [[nodiscard]] std::string get_note()
        {
            return parsed_options_["note"].as<std::string>();
        }
    };
}  // namespace jotter
