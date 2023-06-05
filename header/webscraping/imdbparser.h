#ifndef IMDBPARSER_H
#define IMDBPARSER_H

#include <vector>
#include <string>
#include <sstream>
#include "../database/movie.h"

using std::string;
using std::stringstream;
using std::vector;
using std::endl;

class imdbParser {
    public:
        vector<string> static scrapeGenres(const vector<string>&);
        // string& scrapeMovie(const string&);
    private:

        // set<Director> findDirectorList(stringstream &);
        // set<Actor> findActorList(stringstream &);
        // set<Genre> findGenreList(stringstream &);
        // unsigned findRating(stringstream &);
        // string findTitle(stringstream &);

        void static skipLines(stringstream &, int i);
        void static scrapeMovies(stringstream &, vector<string>&, int i);
};

#endif
