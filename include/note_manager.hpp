#pragma once

#include <config.hpp>

#include <string_view>

namespace jotter
{
    void record_note(std::string_view, const config&);   
}
