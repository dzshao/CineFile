#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <queue>
#include "movie.h"

class UserInterface {
    public:
        char getCharInput();
        void printWelcomeMessage();
        void getSearchKeywords(std::vector<std::string>&);
        void getKeyword(std::string&);
        void printKeywords(std::vector<std::string>& keywords);
        char getRatingsType();
        void printRatingsType(char);
        void printMovieList(std::priority_queue<Movie>&);
};

#endif