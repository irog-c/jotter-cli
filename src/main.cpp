#include <fmt/core.h>
#include <jotter.hpp>

int main(const int argc, const char* argv[]) try
{
    if(argc < 2)
    {
        fmt::println("Nothing no jot, please enter a note like so:");
        fmt::println("\t{} \"<your note>\"", argv[0]);
        return EXIT_FAILURE;
    }

    auto config = jotter::get_config();
    jotter::record_note(argv[1], config);
    

    return EXIT_SUCCESS;
} catch(const std::exception& e)
{
    fmt::println("Exception caught: {}.", e.what());
}
