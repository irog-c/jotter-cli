#include <params.hpp>
#include <note.hpp>

#include <fmt/core.h>
#include <fmt/color.h>

#include <string>
#include <exception>

int main(const int argc, const char* argv[])
try
{
    auto cfg    = jotter::Config();
    auto params = jotter::Params(argc, argv, cfg.get_language());
    if(params.get_help() or params.empty())
    {
        params.print_help();
        return EXIT_SUCCESS;
    }

    auto note = jotter::Note(cfg, params);

    if(params.get_get())
    {
        note.get();
        return EXIT_SUCCESS;
    }

    note.record(params.get_note());

    return EXIT_SUCCESS;
}
catch(const std::exception& e)
{
    fmt::print(fg(fmt::color::crimson), "{}\n", e.what());
}
