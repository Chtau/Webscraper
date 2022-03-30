#include "page.h"

namespace Scraper
{
    
    Page::Page(int level)
    {
        depth_level = level;
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
                auto anchor = Anchor{ value };
                if (anchor.HasValue()) {
                    anchors.push_back(anchor);
                    continue;
                }
                auto mail = Mail{ value };
                if (mail.HasValue()) {
                    mails.push_back(mail);
                    continue;
                }
                auto local = Local { value, url };
                if (local.HasValue()) {
                    locals.push_back(local);
                    continue;
                }
                std::cout << "No Link value match!!! RAW:" << value << std::endl;
            }
        }
    }

    std::vector<Local> Page::GetInternLinks()
    {
        return locals;
    }

    std::vector<Link> Page::GetLinks()
    {
        std::vector<Link> links {};
        links.insert(links.end(), anchors.begin(), anchors.end());
        links.insert(links.end(), mails.begin(), mails.end());
        links.insert(links.end(), locals.begin(), locals.end());
        return links;
    }
}
