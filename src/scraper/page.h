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
        std::string page_base_url;
        std::string url;
        std::vector<Anchor> anchors {};
        std::vector<Local> locals {};
        std::vector<Mail> mails {};
        std::vector<Page> child_pages {};
        int depth_level = 0;
        int depth_max_level = 0;
        bool immediatley_output_links = false;
    public:
        Page(std::string base_url, const bool output_links_immediatley, int max_level = 0, int level = 0);
        ~Page();

        void Load(const std::string new_url);
        std::vector<Link> GetLinks();
        std::vector<Local> GetInternLinks();
    };
}