#include <iostream>

#include "scraper/scraperengine.h"

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
        std::cout << "Missing argument to start scraping (First argument should be a valid url).\n";
    }
    return 0;
}