#pragma once

#include <iostream>

#include "link.h"

namespace Scraper {
    class Anchor : public Link
    {
    private:
        /* data */
    public:
        Anchor(std::string value);
        ~Anchor();
    };
}