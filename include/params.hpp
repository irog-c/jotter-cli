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

        inline void print_help() const
        {
            fmt::println("{}", options_.help());
        }

        [[nodiscard]] inline bool get_help() const
        {
            return parsed_options_.count("help") >= 1u;
        }

        [[nodiscard]] inline bool get_get() const
        {
            return parsed_options_.count("get") >= 1u;
        }

        [[nodiscard]] inline bool get_timestamp() const
        {
            return parsed_options_.count("timestamp") >= 1u;
        }

        [[nodiscard]] inline std::string get_note() const
        {
            return parsed_options_["note"].as<std::string>();
        }
    };
}  // namespace jotter
