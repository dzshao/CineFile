#include "../../header/database/genre.h"

std::string Genre::getName() const {
    return name;
}
std::unordered_map<std::string, Movie>& Genre::getMovieList() {
    return listOfMovies;
}

void Genre::setName(const std::string& newName) {
    name = newName;
}

void Genre::addMovie(const Movie& newMovie) {
    listOfMovies[newMovie.name] = newMovie;
}