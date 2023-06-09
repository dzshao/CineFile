#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <queue>
#include "../database/genre.h"

class UserInterface {
    public:
        char getCharInput();
        void getSearchKeywords(std::vector<std::string>&);
        void getKeyword(std::string&);
        char getRatingsType();
        char getLoopExitInput();
        void printWelcomeMessage();
        void printKeywordInstructions();
        void printKeywords(std::vector<std::string>& keywords);
        void printRatingsType(char);
        void printMovieList(std::priority_queue<Movie>&);
};

#endif