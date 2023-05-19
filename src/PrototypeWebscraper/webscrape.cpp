/* 

This code is just used as a test. It should NOT be included in any final compilation of the program

*/

#include <iostream>
#include <curl/curl.h>
#include <string>
#include <fstream>
#include <sstream>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::stringstream;


size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata)
{
    // This function is called by libcurl when data is received from the website
    // You can process the received data here
    string& text = *static_cast<string*>(userdata);
    size_t totalsize = size * nmemb;
    text.append(static_cast<char*>(ptr), totalsize);

    return totalsize;
}

int main()
{   
    string genreName;
    cout << "Which genre would you like to see? "; 
    std::cin >> genreName;
    cout << endl;
    string URL = "https://www.imdb.com/search/title/?genres=" + genreName;
    string fileName = genreName + ".txt";
    CURL *curl;
    CURLcode res;
    string result;
    
    curl = curl_easy_init();
    if(curl)
    {   
        
        // Set the URL to be scraped
        curl_easy_setopt(curl, CURLOPT_URL, URL.c_str());

        // Set the callback function to be called by libcurl when data is received
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);
        // Perform the scraping
        res = curl_easy_perform(curl);
        if(res != CURLE_OK)
            cout << "Error: " << curl_easy_strerror(res) << endl;

        // Print the result to a .txt file if desired

        // std::ofstream out(fileName);
        // if (out.is_open()) {
        //     out << result << endl;
        // }
        // out.close();

        // Clean up
        curl_easy_cleanup(curl);
    }

    string filter;
    string movieURL;
    string movieName;
    const int numMovies = 10;

    stringstream ss(result);
    ss.ignore(std::numeric_limits<std::streamsize>::max(), ss.widen('\n'));
    getline(ss, filter);

    if (filter != "") {
        cout << "Please enter a valid genre." << endl;
        return 1;
    }

    for (int i = 0; i < 948; ++i) {
        ss.ignore(std::numeric_limits<std::streamsize>::max(), ss.widen('\n'));
    }
    
    getline(ss, filter);
    cout << "Top " << numMovies << " " + genreName + " movies: " << endl;
    for (unsigned i = 0; i < numMovies; ++i) {
        while(filter != "        <div class=\"lister-item-image float-left\">" && getline(ss, filter)) {}
        if (!ss) {
            return 1; 
        }
        filter = "";
        ss.ignore(std::numeric_limits<std::streamsize>::max(), ss.widen('\n'));
        ss.ignore(std::numeric_limits<std::streamsize>::max(), ss.widen('\n'));

        getline(ss, movieURL);
        movieURL = movieURL.substr(9, movieURL.length() - 10);

        getline(ss, movieName);
        movieName = movieName.substr(12, movieName.length() - 13);
        cout << (i + 1) << ". " + movieName << ": " << "https://www.imdb.com" + movieURL << endl;
        for (int i = 0; i < 40; ++i) {
            ss.ignore(std::numeric_limits<std::streamsize>::max(), ss.widen('\n'));
        }
    }

    return 0;
}