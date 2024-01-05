#include <params.hpp>

#include <fmt/core.h>

namespace jotter
{
    cxxopts::Options Params::options_ = cxxopts::Options("jotter", "Command line utility for managing notes");

    Params::Params(const int argc, const char* argv[], std::string_view language)
    {
        if(language == "ru")
        {
            // clang-format off
            options_.add_options()
            ("n,note", "Создать запись", cxxopts::value<std::string>())
            ("t,timestamp", "Отобразить время рядом с записью", cxxopts::value<bool>())
            ("g,get", "Показать все записи")
            ("h,help", "Помощь в использовании");
            // clang-format on
        }
        else
        {
            // clang-format off
            options_.add_options()
            ("n,note", "Note to write", cxxopts::value<std::string>())
            ("t,timestamp", "Display timestamp for each note", cxxopts::value<bool>())
            ("g,get", "Get all notes")
            ("h,help", "Print usage");
            // clang-format on
        }

        parsed_options_ = options_.parse(argc, argv);
        empty_params_   = argc == 1;
    }

    bool Params::get_help()
    {
        return parsed_options_.count("help") >= 1u;
    }

    bool Params::get_get()
    {
        return parsed_options_.count("get") >= 1u;
    }

    bool Params::get_timestamp()
    {
        return parsed_options_.count("timestamp") >= 1u;
    }

    std::string Params::get_note()
    {
        return parsed_options_["note"].as<std::string>();
    }

    bool Params::empty() noexcept
    {
        return empty_params_;
    }

    void Params::print_help()
    {
        fmt::println("{}", options_.help());
    }
}  // namespace jotter
