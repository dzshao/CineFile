#ifndef GENRE_H
#define GENRE_H

#include <string>
#include <unordered_map>
struct Movie;
#include "movie.h"

using std::string;

class Genre {
    public: 
        Genre() :
            name(),
            listOfMovies()
        {};

        Genre(std::string _name) : 
            name(_name)
        {};

        Genre(std::string _name, const std::unordered_map<std::string, Movie>& movies) : 
            name(_name),
            listOfMovies(movies)
        {};

        std::string getName() const;
        std::unordered_map<std::string, Movie>& getMovieList();

        void setName(const std::string&);
        void addMovie(const Movie&);
    private:
        std::string name;
        std::unordered_map<std::string, Movie> listOfMovies;
};

#endif