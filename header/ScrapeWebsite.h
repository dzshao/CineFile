#ifndef SCRAPE_WEBSITE
#define SCRAPE_WEBSITE

#include <string>
#include <iostream>

using std::cout;
using std::string;
using std::endl;

class ScrapeWebsite {
    public:
        static string scrapeSite(const string &);
    private:
       static size_t write_callback(char *, size_t, size_t, void *);
};

#endif