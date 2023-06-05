#ifndef GENRE_H
#define GENRE_H

#include <string>
#include <unordered_map>
#include "movie.h"

class Genre {
    private:
        std::string name;
        std::unordered_map<std::string, Movie> listOfMovies;
};

#endif