#include "../header/ScrapeWebsite.h"
#include <curl/curl.h>

/* This program uses cURL, which will not work on the CS100 server. For this to run, you first need to install cURL
on your computer by running: "sudo apt-get install curl" in the terminal. 
When you compile this program, make sure to add the -lcurl flag. Ex. "g++ ... -lcurl"
*/

size_t ScrapeWebsite::write_callback(char *startPtr, size_t size, size_t nmemb, void *userdata) {
    // This function is called by libcurl when data is received from the website
    string& text = *static_cast<string*>(userdata);
    size_t totalsize = size * nmemb;
    text.append(static_cast<char*>(startPtr), totalsize);

    return totalsize;
}

string ScrapeWebsite::scrapeSite(const string &websiteURL) {
    CURL *websiteConnection = nullptr;
    CURLcode res;
    string siteHTML;
    
    websiteConnection = curl_easy_init();
    if(websiteConnection)
    {   
        // Set the URL to be scraped
        curl_easy_setopt(websiteConnection, CURLOPT_URL, websiteURL.c_str());
        // Set the callback function to be called by libcurl when data is received (write_callback function defined above)
        curl_easy_setopt(websiteConnection, CURLOPT_WRITEFUNCTION, ScrapeWebsite::write_callback);
        curl_easy_setopt(websiteConnection, CURLOPT_WRITEDATA, &siteHTML);
        // Scraping the website
        res = curl_easy_perform(websiteConnection);
        if(res != CURLE_OK) {
            cout << "Error: " << curl_easy_strerror(res) << std::endl;
        }

        // Clean up
        curl_easy_cleanup(websiteConnection);
    }
    return siteHTML;
}