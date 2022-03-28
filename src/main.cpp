#include <iostream>

#include "scraper/scraperengine.h"

int main(int argc, char *argv[])
{
    if (argc >= 2) {
        const std::string url = argv[1];
        Scraper::ScraperEngine engine { };
        engine.Load(url);

        auto links = engine.GetLinks();
        for (size_t i = 0; i < links.size(); i++)
        {
            std::cout << links[i].GetURL() << std::endl;
        }
        
    } else {
        std::cout << "Missing argument to start scraping (First argument should be a valid url).\n";
    }
    return 0;
}