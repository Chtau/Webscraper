#include "page.h"

namespace Scraper
{

    Page::Page(std::string base_url, int max_level, int level)
    {
        page_base_url = base_url;
        depth_level = level;
        depth_max_level = max_level;
    }

    Page::~Page()
    {
    }

    void Page::Load(std::string new_url)
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
                std::string value = urls[i];
                auto anchor = Anchor{value};
                if (anchor.HasValue())
                {
                    anchors.push_back(anchor);
                    continue;
                }
                auto mail = Mail{value};
                if (mail.HasValue())
                {
                    mails.push_back(mail);
                    continue;
                }
                auto local = Local{value, page_base_url};
                if (local.HasValue())
                {
                    locals.push_back(local);
                    continue;
                }
                std::cout << "No Link value match!!! RAW:" << value << std::endl;
            }

            if (depth_max_level > depth_level)
            {
                const int next_level = depth_level + 1;
                for (size_t i = 0; i < locals.size(); i++)
                {
                    auto page = Page{page_base_url, depth_max_level, next_level};
                    page.Load(locals[i].GetURL());
                    child_pages.push_back(page);
                }
            }
        }
        else
        {
            std::cout << "No urls on page:" << url << " content:" << content << std::endl;
        }
    }

    std::vector<Local> Page::GetInternLinks()
    {
        return locals;
    }

    std::vector<Link> Page::GetLinks()
    {
        std::vector<Link> links{};
        links.insert(links.end(), anchors.begin(), anchors.end());
        links.insert(links.end(), mails.begin(), mails.end());
        links.insert(links.end(), locals.begin(), locals.end());
        for (size_t i = 0; i < child_pages.size(); i++)
        {
            auto child_links = child_pages[i].GetLinks();
            links.insert(links.end(), child_links.begin(), child_links.end());
        }
        
        return links;
    }
}
