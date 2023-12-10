#include <iostream>
#include <jotter.hpp>

int main(const int argc, const char* argv[])
{
    if(argc < 2)
    {
        std::cerr << "Nothing no jot, please enter a note like so:\n";
        std::cerr << "\t" << argv[0] << " \"<your note>\"\n";
        return EXIT_FAILURE;
    }

    jotter::record_note(argv[1]);
    return EXIT_SUCCESS;
}