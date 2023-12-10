#include <fmt/core.h>

#include <jotter.hpp>

namespace jotter
{
    void record_note(std::string_view note)
    {
        fmt::println("Recording note: {}", note);
    }
}