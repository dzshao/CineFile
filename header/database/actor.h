#ifndef ACTOR_H
#define ACTOR_H

#include "person.h"

class Actor : public Person {
    public:
        Actor() : Person() 
        {};

        Actor(std::string _name) : Person(_name) 
        {};

        Actor(std::string _name, const std::vector<std::string>&movieList) : Person(_name, movieList) 
        {};
};

#endif