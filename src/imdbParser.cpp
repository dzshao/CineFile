#include "../header/imdbParser.h"
#include "../header/ScrapeWebsite.h"

vector<string>& imdbParser::scrapeGenres(const vector<string>&genreList) {
    const string imdbGenreLink = "https://www.imdb.com/search/title/?genres=";
    for (unsigned i = 0; i < genreList.size(); ++i) {
        stringstream htmlParser(ScrapeWebsite::scrapeSite(imdbGenreLink + genreList.at(i)));

        // Each one of these lines will skip one line in the HTML
        skipLines(htmlParser, 1);

        string filter;
        getline(htmlParser, filter);
        /* The website of a valid genre always begins with two empty lines. Any genre list that is not a valid genre 
        begins with only one empty line. So, if the second line isn't empty, the user did not input a valid genre.
        */
        if (filter != "") {
            cout << "Please enter a valid genre. (" << genreList.at(i) << " is not a valid genre)" << endl;
            continue;
        }
        // Skipping the first 948 lines of the HTML, since the first movie will always show up on line 955
        skipLines(htmlParser, 948);

        const int numMovies = 10;

        for (unsigned i = 0; i < numMovies; ++i) {
            /* Prior to any movie name, this specific line will always appear and only appears before a movie title listing.
            This while loop iterates through and finds this specific line.
            */
            while(filter != "        <div class=\"lister-item-image float-left\">" && getline(htmlParser, filter)) {}
            if (!htmlParser) {
                break;
            }
            filter = "";
            // The next four lines after will be empty and can be skipped
            skipLines(htmlParser, 3);
            string movieName;
            getline(htmlParser, movieName);
            movieName = movieName.substr(12, movieName.length() - 13);
            listOfMovieTitles.push_back(movieName);
        }
    }
    return listOfMovieTitles;
}

void imdbParser::skipLines(stringstream &parser, int i) {
    for (unsigned j = 0; j < i; ++j) {
        parser.ignore(std::numeric_limits<std::streamsize>::max(), parser.widen('\n'));
    }
}