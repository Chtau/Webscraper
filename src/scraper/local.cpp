#include "local.h"

namespace Scraper
{
    Local::Local(std::string value, std::string baseUrl) : Link(value)
    {
        base_url = baseUrl;
        std::regex expression("(href=)\".*?\"");
        std::smatch match;
        if (std::regex_search(value, match, expression))
        {
            url = match[0];
            url = url.substr(0, url.size() - 1);
            url = url.substr(6, url.size());

            if (base_url.back() == '/')
            {
                url = base_url.append(url);
            }
            else
            {
                url = base_url.append("/").append(url);
            }
        }
    }

    Local::~Local()
    {
    }
}