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
        std::vector<Anchor> anchors {};
        std::vector<Local> locals {};
        std::vector<Mail> mails {};
        std::vector<Page> child_pages {};
        int depth_level = 0;
    public:
        Page(int level = 0);
        ~Page();

        void Load(const std::string new_url);
        std::vector<Link> GetLinks();
        std::vector<Local> GetInternLinks();
    };
}