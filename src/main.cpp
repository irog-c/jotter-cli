#include <fmt/core.h>
#include <jotter.hpp>

int main(const int argc, const char* argv[])
{
    if(argc < 2)
    {
        fmt::println("Nothing no jot, please enter a note like so:");
        fmt::println("\t{} \"<your note>\"", argv[0]);
        return EXIT_FAILURE;
    }

    jotter::record_note(argv[1]);

    return EXIT_SUCCESS;
}