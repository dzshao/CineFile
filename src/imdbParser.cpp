#include "../header/webscraping/imdbParser.h"
#include "../header/webscraping/ScrapeWebsite.h"

vector<Movie> imdbParser::scrapeGenres(const vector<string>&genreList) {
    const string imdbGenreLink = "https://www.imdb.com/search/title/?genres=";
    vector<Movie> listOfMovies;
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
        // Skipping the first 930 lines of the HTML, since the first movie will always show up on line 955
        skipLines(htmlParser, 930);

        const int numMovies = 10;
        scrapeMovies(htmlParser, listOfMovies, numMovies);
    }
    return listOfMovies;
}

void imdbParser::skipLines(stringstream &parser, int i) {
    for (unsigned j = 0; j < i; ++j) {
        parser.ignore(std::numeric_limits<std::streamsize>::max(), parser.widen('\n'));
    }
}

void imdbParser::scrapeMovies(stringstream& parser, vector<Movie>& movieList, int numMovies) {
    for (unsigned i = 0; i < numMovies; ++i) {
        string movieTitle = findTitle(parser);
        string releaseDate = findReleaseDate(parser);
        vector<Genre> movieGenres = findGenreList(parser);
        double movieRating = findRating(parser);
        vector<Director> directorList = findDirectorList(parser);
        vector<Actor> actorList = findActorList(parser);

        movieList.push_back({movieTitle, movieRating, releaseDate, movieGenres, directorList, actorList});
    }
}

string imdbParser::findTitle(stringstream &parser) {
    /* Prior to any movie name, this specific line will always appear and only appears before a movie title listing.
    This while loop iterates through and finds this specific line.
    */
    string filter;
    while(filter != "        <div class=\"lister-item-image float-left\">" && getline(parser, filter)) 
    {}
    if (!parser) {
        return "Error retrieving title";
    }

    // The next four lines after will be empty and can be skipped
    skipLines(parser, 3);

    string movieName;
    getline(parser, movieName);
    return movieName.substr(12, movieName.length() - 13);
}

// These functions are stubs for now.
string imdbParser::findReleaseDate(stringstream &parser) {
    string filter;
    while(filter.substr(0, 53) != "    <span class=\"lister-item-year text-muted unbold\">" && getline(parser, filter)) 
    {}
    if (!parser) {
        return "Error retrieving release date";
    }
    
    string releaseDate = filter.substr(53, filter.length() - 60);
    for (int i = releaseDate.length() - 1; i >=0; --i) {
        if (releaseDate.at(i) == '(') {
            releaseDate = releaseDate.substr(i, releaseDate.length() - i);
            break;
        }
    }
    
    return releaseDate;
}

double imdbParser::findRating(stringstream &parser) {
    return 0.0; // Stub function for now
}

vector<Genre> imdbParser::findGenreList(stringstream &parser) {
    return {};
}

vector<Director> imdbParser::findDirectorList(stringstream &parser) {
    return {};
}

vector<Actor> imdbParser::findActorList(stringstream &parser) {
    return {};
}