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
using std::set;

class imdbParser {
    public:
        vector<Movie> static scrapeGenres(const vector<string>&);
        // string& scrapeMovie(const string&);
    private:
        string static findTitle(stringstream &);
        unsigned static findRating(stringstream &);
        set<Genre> static findGenreList(stringstream &);
        set<Director> static findDirectorList(stringstream &);
        set<Actor> static findActorList(stringstream &);

        void static skipLines(stringstream &, int i);
        void static scrapeMovies(stringstream &, vector<Movie>&, int i);
};

#endif
