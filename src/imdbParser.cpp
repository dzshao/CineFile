#include "../header/webscraping/imdbParser.h"
#include "../header/webscraping/ScrapeWebsite.h"

void imdbParser::scrapeGenres(const vector<string>&genreList) {
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
        if (filter != "" || !htmlParser) {
            cout << "Please enter a valid genre. (" << genreList.at(i) << " is not a valid genre)" << endl;
            continue;
        }

        const int numMovies = 10;
        scrapeMovies(htmlParser, listOfMovies, numMovies);
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

        movieList.push_back({movieTitle, releaseDate, movieGenres, movieRating, directorList, actorList});
        MoviesDatabase::addMovie(movieList.at(i));
    }
}

string imdbParser::findTitle(stringstream &parser) {
    /* Prior to any movie name, this specific line will always appear and only appears before a movie title listing.
    This function iterates through and finds this specific line.
    */
    findHTML(parser, "        <div class=\"lister-item-image float-left\">");
    if (!parser) {
        return "Error retrieving title";
    }

    // The next four lines after will be empty and can be skipped
    skipLines(parser, 3);

    string movieName;
    getline(parser, movieName);
    return movieName.substr(12, movieName.length() - 13);
}

string imdbParser::findReleaseDate(stringstream &parser) {
    findHTML(parser, "<h3 class=\"lister-item-header\">");
    if (!parser) {
        return "Error getting release date";
    }
    skipLines(parser, 4);

    string releaseDate;
    getline(parser, releaseDate);

    releaseDate = releaseDate.substr(53, releaseDate.length() - 60);

    for (int i = releaseDate.length() - 1; i >=0; --i) {
        if (releaseDate.at(i) == '(') {
            releaseDate = releaseDate.substr(i, releaseDate.length() - i);
            break;
        }
    }

    return releaseDate;
}

vector<Genre> imdbParser::findGenreList(stringstream &parser) {
    findHTML(parser, "            <span class=\"genre\">");

    if (!parser) {
        return {{"Error getting genres"}};
    }
    string genres;
    getline(parser, genres);
    genres = genres.substr(0, genres.length() - 19);

    vector<Genre> genreList;
    stringstream genreParse(genres);
    while (genreParse >> genres) {
        if (genres.at(genres.length() - 1) == ',') {
            genreList.push_back({genres.substr(0, genres.length() - 1)});
        } else {
            genreList.push_back({genres});
        }
    }

    return genreList;
}

double imdbParser::findRating(stringstream &parser) {
    string filter;
    getline(parser, filter);
    // Some movies aren't released yet and thus won't have a rating. 
    // This statement checks for that and returns a rating of N/A if there's no rating yet.
    if (filter == "                     <span class=\"ghost\">|</span> ") {
        return 0.0;
    }
    findHTML(parser, "        <span class=\"global-sprite rating-star imdb-rating\"></span>");

    string ratingString;
    getline(parser, ratingString);

    // Extracting the rating value out of the line of HTML
    ratingString = ratingString.substr(16, 3);
    
    return std::stod(ratingString);
}

vector<Director> imdbParser::findDirectorList(stringstream &parser) {
    findHTML(parser, "    <p class=\"\">");
    string directorCheck;
    getline(parser, directorCheck);
    if (directorCheck == "            ") return {{"N/A"}};
    
    vector<Director> directorList;
    string directorFinder;
    getline(parser, directorFinder);
    while (directorFinder != "                 <span class=\"ghost\">|</span> ") {
        getline(parser, directorFinder);
        if(directorFinder.at(directorFinder.length() - 2) == ',') {
            directorFinder = directorFinder.substr(0, directorFinder.length() - 2);
        }
        string directorName = directorFinder.substr(1, directorFinder.length() - 5);
        directorList.push_back({directorName});
        getline(parser, directorFinder);
    }

    return directorList;
}

vector<Actor> imdbParser::findActorList(stringstream &parser) {
    skipLines(parser, 1);

    string actorFinder;
    getline(parser, actorFinder);

    vector<Actor> actorList;
    while(actorFinder != "    </p>" ) {
        getline(parser, actorFinder);
        if(actorFinder.at(actorFinder.length() - 2) == ',') {
            actorFinder = actorFinder.substr(0, actorFinder.length() - 2);
        }
        string actorName = actorFinder.substr(1, actorFinder.length() - 5);
        actorList.push_back({actorName});
        getline(parser, actorFinder);
    }

    return actorList;
}

void imdbParser::findHTML(stringstream &parser, const string &textToFind) {
    string filter;
    while(filter != textToFind && getline(parser, filter)) 
    {}
}

void imdbParser::skipLines(stringstream &parser, int i) {
    for (unsigned j = 0; j < i; ++j) {
        parser.ignore(std::numeric_limits<std::streamsize>::max(), parser.widen('\n'));
    }
}