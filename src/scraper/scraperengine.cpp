#include <regex>

#include "scraperengine.h"

namespace Scraper
{

    ScraperEngine::ScraperEngine()
    {
    }

    ScraperEngine::~ScraperEngine()
    {
    }

    void ScraperEngine::Load(const std::string new_url, const bool output_links_immediatley, const int discover_level_depth)
    {
        auto page = Page{new_url, output_links_immediatley, discover_level_depth};
        page.Load(new_url);
        pages.push_back(page);
    }

    std::vector<Link> ScraperEngine::GetLinks()
    {
        std::vector<Link> links{};
        for (size_t i = 0; i < pages.size(); i++)
        {
            auto p_links = pages[i].GetLinks();
            links.insert(links.end(), p_links.begin(), p_links.end());
        }
        return links;
    }
}