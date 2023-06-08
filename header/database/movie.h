#ifndef MOVIE_H
#define MOVIE_H

#include <set>
#include <vector>
#include <string>
#include <iostream>

#include "actor.h"
#include "director.h"
class Genre;
#include "genre.h"

struct Movie {
    std::string name;
    std::string releaseDates;
    std::vector<Genre> genreList;
    double rating;
    std::vector<Director> directorList;
    std::vector<Actor> castList;

    friend std::ostream& operator<<(std::ostream& out, const Movie& outputMovie);
};

#endif