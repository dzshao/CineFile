#include "../../header/database/director.h"

std::vector<std::string>& Director::getMovieList() {
    return movies;
}

void Director::addMovie(const Movie& newMovie) {
    movies.push_back(newMovie.name);
}
void Director::addMovie(const std::string& newMovieTitle) {
    movies.push_back(newMovieTitle);
}