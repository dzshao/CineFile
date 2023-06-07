#ifndef MOVIE_H
#define MOVIE_H

#include <set>
#include <vector>

#include "actor.h"
#include "director.h"
#include "genre.h"

struct Movie {
    std::string name;
    double rating;
    std::string releaseDates;
    std::vector<Genre> genreList;
    std::vector<Director> directorList;
    std::vector<Actor> castList;
};

#endif