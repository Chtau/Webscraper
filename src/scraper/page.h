#pragma once

#include <iostream>
#include "anchor.h"
#include "local.h"
#include "mail.h"

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Exception.hpp>
#include <curlpp/Infos.hpp>

#include "../includes/httpdownloader.h"

namespace Scraper {
    class Page
    {
    private:
        std::string url;
        std::vector<Link> links;
    public:
        Page(/* args */);
        ~Page();

        void Load(const std::string new_url);
        std::vector<Link> GetLinks() { return links; }
    };
}