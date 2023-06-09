#ifndef IMDBPARSER_H
#define IMDBPARSER_H

#include <vector>
#include <string>
#include <sstream>
#include <limits>
#include "../database/moviesDatabase.h"
#include "../database/genre.h"

using std::string;
using std::stringstream;
using std::vector;
using std::endl;

class imdbParser {
    public:
        void static scrapeGenres(const vector<string>&);
        void static scrapeMovies(stringstream &, vector<Movie>&, int i);

    private:
        string static findTitle(stringstream &);
        string static findReleaseDate(stringstream &);
        vector<Genre> static findGenreList(stringstream &);
        double static findRating(stringstream &);
        vector<Director> static findDirectorList(stringstream &);
        vector<Actor> static findActorList(stringstream &);

        void static skipLines(stringstream &, int i);
        void static findHTML(stringstream &, const string &);
};

#endif
