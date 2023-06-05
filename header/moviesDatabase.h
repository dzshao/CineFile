#ifndef MOVIES_DATABASE
#define MOVIES_DATABASE

#include <string>
#include <unordered_map>
#include <iostream>

using std::cout;
using std::string;

class MoviesDatabase {
    public:
        void loadMovies(const string&);
    private:
       unordered_map<string, Genre> allGenres;
       unordered_map<string, Actors> allActors;
       unordered_map<string, Directors> allDirectors; 

};

#endif