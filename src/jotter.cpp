#include <iostream>

#include <jotter.hpp>

namespace jotter
{
    void record_note(std::string_view note)
    {
        std::cout << "Recording note.\n";
        std::cout << note << '\n';
    }
}