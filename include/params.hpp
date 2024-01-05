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
        bool empty() noexcept;
        void print_help();

        bool get_help();
        bool get_get();
        bool get_timestamp();
        std::string get_note();
    };
}  // namespace jotter
