#include "anchor.h"

namespace Scraper
{
    Anchor::Anchor(std::string value) : Link::Link(value)
    {
        std::regex expression("\"(http).*?\"");
        std::smatch match;
        if (std::regex_search(value, match, expression))
        {
            url = match[0];
        }
    }

    Anchor::~Anchor()
    {
    }
}