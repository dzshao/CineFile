#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "person.h"

class Director : public Person {
    public:
        Director() : Person() 
        {};

        Director(std::string _name) : Person(_name) 
        {};

        Director(std::string _name, const std::vector<std::string>&movieList) : Person(_name, movieList) 
        {};
};

#endif