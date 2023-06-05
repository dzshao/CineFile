#ifndef IMDBPARSER_H
#define IMDBPARSER_H

#include <vector>
#include <string>
#include <sstream>
#include <limits>
#include "../database/movie.h"

using std::string;
using std::stringstream;
using std::vector;
using std::endl;

class imdbParser {
    public:
        vector<Movie> static scrapeGenres(const vector<string>&);
        // string& scrapeMovie(const string&);
    private:

        // set<Director> findDirectorList(stringstream &);
        // set<Actor> findActorList(stringstream &);
        // set<Genre> findGenreList(stringstream &);
        unsigned static findRating(stringstream &);
        string static findTitle(stringstream &);

        void static skipLines(stringstream &, int i);
        void static scrapeMovies(stringstream &, vector<Movie>&, int i);
};

#endif
