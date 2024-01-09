#include <params.hpp>

namespace jotter
{

    Params::Params(const int argc, const char* argv[], std::string_view language)
        : options_(cxxopts::Options("jotter", "Command line utility for managing notes"))
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
}  // namespace jotter
