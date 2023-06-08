#ifndef MOVIES_DATABASE
#define MOVIES_DATABASE

#include <string>
#include <unordered_map>
#include <iostream>
#include "actor.h"
#include "director.h"
#include "genre.h"
#include "movie.h"
#include "person.h"

using std::cout;
using std::string;

class MoviesDatabase {
    public:
        void loadMovies(const string&);
        void addGenre(const genre&);
        void addActor(const actor&);
        void addDirector(const director&)
    private:
       unordered_map<string, Genre> allGenres;
       unordered_map<string, Actors> allActors;
       unordered_map<string, Directors> allDirectors; 

};

#endif