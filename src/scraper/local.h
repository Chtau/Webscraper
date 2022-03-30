#include "link.h"

namespace Scraper {
    class Local : public Link
    {
    private:
        std::string base_url;
        std::string raw_url;
    public:
        Local(std::string value, std::string baseUrl);
        ~Local();
        std::string GetRaw() { return raw_url; }
    };
}