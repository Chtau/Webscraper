#pragma once

#include <iostream>
#include <regex>

namespace Scraper {
    class Link
    {
    protected:
        std::string raw;
        std::string url;
    public:
        Link(std::string value);
        ~Link();
        virtual std::string GetURL() { return url; }
        bool HasValue() { return url.size() > 0; }
    };
}