#include <note_manager.hpp>

#include <fmt/core.h>
#include <cxxopts.hpp>

#include <algorithm>
#include <string>

static auto parse_options(const int argc, const char* argv[])
{
    auto options = cxxopts::Options("jotter", "Command line utility for managing notes");
    options.add_options()
    ("n,note", "Note to write", cxxopts::value<std::string>());

    return options.parse(argc, argv);
}

int main(const int argc, const char* argv[]) try
{
/*    if(argc < 2)
    {
        fmt::println("Nothing no jot, please enter a note like so:");
        fmt::println("\t{} \"<your note>\"", argv[0]);
        return EXIT_FAILURE;
    }*/

    auto parsed_options = parse_options(argc, argv);
    
    fmt::println("{}", parsed_options["note"].as<std::string>());

    auto config = jotter::get_config();
    jotter::record_note(argv[1], config);

    return EXIT_SUCCESS;
}
catch(const std::exception& e)
{
    fmt::println("Exception caught: {}.", e.what());
}
