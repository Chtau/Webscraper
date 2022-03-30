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

    void ScraperEngine::Load(const std::string new_url, const int discover_level_depth)
    {
        auto page = Page{};
        page.Load(new_url);
        pages.push_back(page);

        if (discover_level_depth > 0)
        {
            auto intern_links = page.GetInternLinks();
            for (size_t i = 0; i < intern_links.size(); i++)
            {
                auto page = Page{};
                page.Load(intern_links[i].GetURL());
                pages.push_back(page);
            }
        }
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