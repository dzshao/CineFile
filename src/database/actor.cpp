#include "../../header/database/actor.h"

std::vector<std::string>& Actor::getMovieList() {
    return movies;
}

void Actor::addMovie(const Movie& newMovie) {
    movies.push_back(newMovie.name);
}
void Actor::addMovie(const std::string& newMovieTitle) {
    movies.push_back(newMovieTitle);
}