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

        void Load(const std::string new_url, const bool output_links_immediatley = false, const int discover_level_depth = 0);
        std::vector<Link> GetLinks();
    };
}