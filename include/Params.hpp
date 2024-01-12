#pragma once

#include <fmt/core.h>
#include <cxxopts.hpp>

#include <string_view>

namespace Jotter
{
    class Params
    {
       private:
        cxxopts::Options options_;
        cxxopts::ParseResult parsedOptions_;
        bool emptyParams_;

       public:
        Params() = delete;

        Params(int argc, const char* argv[], std::string_view language);

        [[nodiscard]] constexpr bool empty() const noexcept
        {
            return emptyParams_;
        }

        inline void printHelp() const
        {
            fmt::println("{}", options_.help());
        }

        [[nodiscard]] inline bool isHelpRequested() const
        {
            return parsedOptions_.count("help") >= 1u;
        }

        [[nodiscard]] inline bool isGetRequested() const
        {
            return parsedOptions_.count("get") >= 1u;
        }

        [[nodiscard]] inline bool isTimestampRequested() const
        {
            return parsedOptions_.count("timestamp") >= 1u;
        }

        [[nodiscard]] inline std::string getNote() const
        {
            return parsedOptions_["note"].as<std::string>();
        }
    };
}  // namespace jotter
