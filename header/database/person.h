#ifndef PERSON_H
#define PERSON_H

#include <vector>

class Person {
    protected:
        std::vector<std::string> movies;
    public:
        std::vector<std::string>& getMovieList();
};

#endif