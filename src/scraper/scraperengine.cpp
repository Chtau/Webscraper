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
        std::cout << content << std::endl;
        
    }

}