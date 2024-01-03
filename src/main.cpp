#include <note.hpp>

#include <fmt/core.h>
#include <fmt/color.h>
#include <cxxopts.hpp>

#include <string>
#include <exception>

static auto options = cxxopts::Options("jotter", "Command line utility for managing notes");

[[nodiscard]] static auto parse_options(const int argc, const char* argv[], jotter::config& cfg)
{
    if(cfg.language == "ru")
    {
        // clang-format off
        options.add_options()
        ("n,note", "Создать запись", cxxopts::value<std::string>())
        ("t,timestamp", "Отобразить время рядом с записью", cxxopts::value<bool>())
        ("g,get", "Показать все записи")
        ("h,help", "Помощь в использовании");
        // clang-format on
    }
    else
    {
        // clang-format off
        options.add_options()
        ("n,note", "Note to write", cxxopts::value<std::string>())
        ("t,timestamp", "Display timestamp for each note", cxxopts::value<bool>())
        ("g,get", "Get all notes")
        ("h,help", "Print usage");
        // clang-format on
    }

    auto parsed_options = options.parse(argc, argv);

    if(parsed_options.count("timestamp") >= 1u) cfg.with_timestamp = parsed_options["timestamp"].as<bool>();

    return parsed_options;
}

int main(const int argc, const char* argv[])
try
{
    auto cfg            = jotter::get_config();
    auto parsed_options = parse_options(argc, argv, cfg);
    if(parsed_options.count("help") >= 1u or argc == 1)
    {
        fmt::println("{}", options.help());
        return EXIT_SUCCESS;
    }

    auto note = jotter::Note(cfg);

    if(parsed_options.count("get"))
    {
        note.get();
        return EXIT_SUCCESS;
    }

    auto note_arg = parsed_options["note"].as<std::string>();
    note.record(note_arg);

    return EXIT_SUCCESS;
}
catch(const std::exception& e)
{
    fmt::print(fg(fmt::color::crimson), "{}\n", e.what());
}
