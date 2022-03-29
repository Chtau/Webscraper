#pragma once

#include <iostream>

#include "page.h"

namespace Scraper
{

    class ScraperEngine
    {
    private:
        std::vector<Page> pages {};        
    public:
        ScraperEngine();
        ~ScraperEngine();

        void Load(const std::string new_url);
        std::vector<Link> GetLinks();
    };
}