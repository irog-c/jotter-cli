#include <note_manager.hpp>

#include <fmt/core.h>
#include <fmt/color.h>
#include <cxxopts.hpp>

#include <string>
#include <exception>

static auto options = cxxopts::Options("jotter", "Command line utility for managing notes");

[[nodiscard]] static auto init_options(const int argc, const char* argv[], [[maybe_unused]] jotter::config& cfg)
{
    options.add_options()("n,note", "Note to write", cxxopts::value<std::string>())("h,help", "Print usage");

    return options.parse(argc, argv);
}

int main(const int argc, const char* argv[])
try
{
    auto config         = jotter::get_config();
    auto parsed_options = init_options(argc, argv, config);
    if(parsed_options.count("help") || argc == 1)
    {
        fmt::println("{}", options.help());
        return EXIT_SUCCESS;
    }

    auto note = parsed_options["note"].as<std::string>();
    jotter::record_note(note, config);

    return EXIT_SUCCESS;
}
catch(const std::exception& e)
{
    fmt::print(fg(fmt::color::crimson), "{}\n", e.what());
}
