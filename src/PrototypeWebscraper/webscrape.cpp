/* 

This code is just used as a test. It should NOT be included in any final compilation of the program.
This program uses cURL, which will not work on the CS100 server. For this to run, you first need to install cURL
on your computer by running: "sudo apt-get install curl" in the terminal. 
When you compile this program, make sure to add the -lcurl flag. Ex. "g++ webscrape.cpp -lcurl"

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
    cin >> genreName;
    cout << endl;
    /* All genre search URLs follow the same formatting, simply having the name of the genre listed at the end of the URL.
    We can search for multiple genres at once by adding a comma between genre names. 
    Ex. "https://www.imdb.com/search/title/?genres=horror,comedy,action"
    */
    string URL = "https://www.imdb.com/search/title/?genres=" + genreName;
    // This is just used for prototyping. If desired, the HTML of the scraped page can be output to a .txt file.
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

        std::ofstream out(fileName);
        if (out.is_open()) {
            out << result << endl;
        }
        out.close();

        // Clean up
        curl_easy_cleanup(curl);
    }

    string filter;
    string movieURL;
    string movieName;
    // numMovies is the number of movies that will be parsed. 
    const int numMovies = 10;

    /* Check to see if the website is a valid genre. A valid genre list will have 2 empty lines at the start, while anything else 
    will have only 1 empty line. 
    */
    stringstream ss(result);
    ss.ignore(std::numeric_limits<std::streamsize>::max(), ss.widen('\n'));
    getline(ss, filter);

    if (filter != "") {
        cout << "Please enter a valid genre." << endl;
        return 1;
    }
    
    // Skipping the first 948 lines of the HTML, since the first movie will always show up on line 955
    for (int i = 0; i < 948; ++i) {
        ss.ignore(std::numeric_limits<std::streamsize>::max(), ss.widen('\n'));
    }
    
    cout << "Top " << numMovies << " " + genreName + " movies: " << endl;

    /* For loop iterates through the HTML to find the first numMovies amount of movies on the website. Any value greater than 50
    will only find 50 movies, since each web page only lists 50 movies.
    */
    for (unsigned i = 0; i < numMovies; ++i) {
        /* Prior to any movie name, this specific line will always appear and only appears before a movie title listing.
        This while loop iterates through and finds this specific line.
        */
        while(filter != "        <div class=\"lister-item-image float-left\">" && getline(ss, filter)) {}
        if (!ss) {
            return 1; 
        }
        filter = "";
        // The next two lines after will be empty and can be skipped
        ss.ignore(std::numeric_limits<std::streamsize>::max(), ss.widen('\n'));
        ss.ignore(std::numeric_limits<std::streamsize>::max(), ss.widen('\n'));

        /* The line after will contain a reference to the URL of the movie's imdb page. 
        The substr is used to extract this URL from the entire line.
        */
        getline(ss, movieURL);
        movieURL = movieURL.substr(9, movieURL.length() - 10);

        /* The next line contains the title of the movie.
        Substr is used to extract the exact title from the line.
        */
        getline(ss, movieName);
        movieName = movieName.substr(12, movieName.length() - 13);
        cout << (i + 1) << ". " + movieName << ": " << "https://www.imdb.com" + movieURL << endl;

        // Skips forward another 40 lines. There is always at least 40 lines between movie titles, so we can just skip through them
        for (int i = 0; i < 40; ++i) {
            ss.ignore(std::numeric_limits<std::streamsize>::max(), ss.widen('\n'));
        }
    }

    return 0;
}