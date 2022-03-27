#pragma once

#include <iostream>

namespace Scraper
{

    class ScraperEngine
    {
    private:
        std::string url;
    public:
        ScraperEngine();
        ~ScraperEngine();

        void Load(const std::string new_url);
    };
}