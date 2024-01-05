#pragma once

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
        [[nodiscard]] bool empty() noexcept;
        void print_help();

        [[nodiscard]] bool get_help();
        [[nodiscard]] bool get_get();
        [[nodiscard]] bool get_timestamp();
        [[nodiscard]] std::string get_note();
    };
}  // namespace jotter
