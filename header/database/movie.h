#ifndef MOVIE_H
#define MOVIE_H

#include <set>
#include <string>

#include "actor.h"
#include "director.h"
#include "genre.h"

struct Movie {
    std::string name;
    double rating;
    unsigned releaseYear;
    std::set<Genre> genreList;
    std::set<Director> directorList;
    std::set<Actor> castList;
};

#endif