#include "Params.hpp"
#include "Note.hpp"
#include "ConfigFactory.hpp"

#include <fmt/color.h>

#include <string>
#include <exception>

int main(const int argc, const char* argv[])
try
{
    auto cfg = Jotter::ConfigFactory::create();
    auto params = Jotter::Params(argc, argv, cfg.getLanguage());

    if(params.isHelpRequested() or params.empty())
    {
        params.printHelp();
        return EXIT_SUCCESS;
    }

    auto note = Jotter::Note(cfg, params);

    if(params.isGetRequested())
    {
        note.get();
        return EXIT_SUCCESS;
    }

    note.record(params.getNote());

    return EXIT_SUCCESS;
}
catch(const std::exception& e)
{
    fmt::print(fg(fmt::color::crimson), "{}\n", e.what());
}
