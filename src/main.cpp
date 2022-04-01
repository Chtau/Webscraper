#include <iostream>

#include "scraper/scraperengine.h"


void help()
{
    std::cout << "Webscraper" << std::endl;
    std::cout << "Version: 0.1.0" << std::endl;
    std::cout << "Author:  Christoph Taucher <taucher.ch@gmail.com>" << std::endl;

    std::cout << "Argument    Example                           Description" << std::endl;
    std::cout << "1.)         https://news.ycombinator.com/     First argument must always be the url to scrape" << std::endl;
    std::cout << "-l={number} -l=2                              Scraping depth, default is 0 which means only the provided page will be scraped" << std::endl;
    std::cout << "-o          -o                                When provided all found links will immediatley be written to the output" << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc >= 2) {
        int depth_level = 0;
        bool output_links_immediatley = false;
        std::vector<std::string> arguments {};
        for (size_t i = 0; i < argc; i++)
        {
            const std::string value = argv[i];
            arguments.push_back(value);
            auto comp = value.compare("-l=");
            if (comp == value.size() - 3) {
                depth_level = std::stoi(value.substr(3, value.size() - 3));
                std::cout << "Argument for Depth level:" << depth_level << std::endl;        
            }
            auto comp_output = value.compare("-o");
            if (comp_output == value.size() - 2) {
                output_links_immediatley = true;
                std::cout << "Argument for immediatley output links:" << output_links_immediatley << std::endl;        
            }
        }
        

        const std::string url = argv[1];
        Scraper::ScraperEngine engine { };
        engine.Load(url, output_links_immediatley, depth_level);

        auto links = engine.GetLinks();
        std::cout << "Total Urls discovered:" << links.size() << std::endl;
        for (size_t i = 0; i < links.size(); i++)
        {
            std::cout << links[i].GetURL() << std::endl;
        }
        
    } else {
        help();
    }
    return 0;
}
