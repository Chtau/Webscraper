#include "link.h"

namespace Scraper {
    class Local : public Link
    {
    private:
        std::string base_url;
    public:
        Local(std::string value, std::string baseUrl);
        ~Local();
    };
}