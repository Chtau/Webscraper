#include <regex>

#include "scraperengine.h"

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Exception.hpp>
#include <curlpp/Infos.hpp>

#include "../includes/httpdownloader.h"

namespace Scraper
{

    ScraperEngine::ScraperEngine()
    {
    }

    ScraperEngine::~ScraperEngine()
    {
    }

    void ScraperEngine::Load(const std::string new_url)
    {
        url = new_url;

        HTTPDownloader downloader;
        std::string content = downloader.download(url);
        std::regex expression("<a[^>]+href=\"(.*?)\"[^>]*>(.*)?</a>");
        std::string word;
        std::stringstream ss(content);
        std::vector<std::string> urls;
        std::smatch sm;

        while (std::regex_search(content, sm, expression))
        {
            urls.push_back(sm.str());
            content = sm.suffix();
        }

        std::cout << "Urls found: " << urls.size() << std::endl;

        if (urls.size() > 0)
        {
            for (size_t i = 0; i < urls.size(); i++)
            {
                std::cout << "Url:" << urls[i] << std::endl;
            }
        }
    }

}