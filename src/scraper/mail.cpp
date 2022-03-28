#include "mail.h"

namespace Scraper {
    Mail::Mail(std::string value) : Link(value)
    {
        std::regex expression("\"(mailto:).*?\"");
        std::smatch match;
        if (std::regex_search(value, match, expression))
        {
            url = match[0];
            url = url.substr(0, url.size() - 1);
            url = url.substr(8, url.size());
        }
    }
    
    Mail::~Mail()
    {
    }   
}