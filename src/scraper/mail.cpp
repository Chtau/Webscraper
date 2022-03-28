#include "mail.h"

namespace Scraper {
    Mail::Mail(std::string value) : Link(value)
    {
        std::regex expression("\"(mailto:).*?\"");
        std::smatch match;
        if (std::regex_search(value, match, expression))
        {
            url = match[0];
        }
    }
    
    Mail::~Mail()
    {
    }
    
}