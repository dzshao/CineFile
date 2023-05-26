#ifndef IMDBPARSER_H
#define IMDBPARSER_H

#include <vector>
#include <string>
#include <sstream>

using std::string;
using std::stringstream;
using std::vector;
using std::endl;

class imdbParser {
    public:
        vector<string>& scrapeGenres(const vector<string>&);
        // string& scrapeMovie(const string&);
    private:
        vector<string> listOfMovieTitles;


        // set<Director> findDirectorList(const string&);
        // set<Actor> findActorList(const string&);
        // set<Genre> findGenreList(const string&);
        // unsigned findRating(const string&);
        // string findTitle(const string&);

        void skipLines(stringstream &, int i);
};

#endif
