#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <queue>
#include "movie.h"

class UserInterface {
    public:
        char getCharInput();
        void printWelcomeMessage();
        char getSearchType();
        char getRatingsType();
        void printMovieList(std::priority_queue<Movie> &);
};

#endif