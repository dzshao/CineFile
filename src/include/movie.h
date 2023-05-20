#ifndef MOVIE_H
#define MOVIE_H

#include <set>
#include <string>

#include "actor.h"
#include "director.h"

struct Movie {
    std::string name;
    double rating;
    unsigned releaseYear;
    //Missing std::set<Genres> genreList; because of circular includes
    std::set<Director> directorList;
    std::set<Actor> castList;
};

#endif