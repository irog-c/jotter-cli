#pragma once

#include <Params.hpp>
#include <Config.hpp>
#include "interface/ICommon.hpp"

#include <string_view>

namespace Jotter
{
    class Note
    {
       private:
        struct Entry
        {
            std::string_view entryText;

            epoch creationTime;

            explicit Entry(std::string_view note, ICommon& common);

            void writeToFile(auto&) const;
        };

       private:
        const Config& cfg_;

        const Params& params_;

       public:
        Note() = delete;

        Note(const Config&, const Params&);

        void get() const;

        void record(std::string_view) const;
    };
}  // namespace Jotter
