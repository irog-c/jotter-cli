#pragma once

#include <string_view>
#include <string>

#include <config.hpp>

namespace jotter
{
    void record_note(std::string_view, const config&);   
}
