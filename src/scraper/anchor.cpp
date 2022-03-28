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
            url = url.substr(0, url.size() - 1);
            url = url.substr(1, url.size());
        }
    }

    Anchor::~Anchor()
    {
    }
}