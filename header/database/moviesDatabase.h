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
        void static loadMovies();
        void static storeMovies();
        void static addGenre(const Genre&);
        void static addActor(const Actor&);
        void static addDirector(const Director&);
        void static addMovie(Movie);
        static Genre& getGenre(const string&);
        static Actor& getActor(const string&);
        static Director& getDirector(const string&);
        static Movie& getMovie(const string&);
        static std::unordered_map<string, Movie>&  getMovieList();
        static std::unordered_map<string, Genre>&  getGenreList();
        static std::unordered_map<string, Director>&  getDirectorList();
        static std::unordered_map<string, Actor>&  getActorList();
    private:
        static std::unordered_map<string, Genre> allGenres;
        static std::unordered_map<string, Actor> allActors;
        static std::unordered_map<string, Director> allDirectors; 
        static std::unordered_map<string, Movie> allMovies;
};

#endif