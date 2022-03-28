#pragma once

#include <iostream>

#include "anchor.h"
#include "mail.h"
#include "local.h"

namespace Scraper
{

    class ScraperEngine
    {
    private:
        std::string url;
        std::vector<Link> links;
    public:
        ScraperEngine();
        ~ScraperEngine();

        void Load(const std::string new_url);
    };
}