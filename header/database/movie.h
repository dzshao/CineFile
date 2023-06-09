#ifndef MOVIE_H
#define MOVIE_H

#include <set>
#include <vector>
#include <string>
#include <iostream>
class Genre;
class Actor;
class Director;
#include "actor.h"
#include "director.h"
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