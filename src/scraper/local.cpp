#include "local.h"

namespace Scraper {   
    Local::Local(std::string value) : Link(value)
    {
        std::regex expression("(href=)\".*?\"");
        std::smatch match;
        if (std::regex_search(value, match, expression))
        {
            url = match[0];
        }
    }
    
    Local::~Local()
    {
    }
    
}