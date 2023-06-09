#ifndef ACTOR_H
#define ACTOR_H

#include "person.h"
#include "genre.h"

using std::string;

class Actor : public Person {
    public:
        Actor() : Person() 
        {};

        Actor(std::string _name) : Person(_name) 
        {};

        Actor(std::string _name, const std::vector<std::string>&movieList) : 
                Person(_name),
                movies(movieList)
        {};

        std::vector<std::string>& getMovieList();
        void addMovie(const Movie&);
        void addMovie(const std::string&);

    private: 
        std::vector<std::string> movies;
};

#endif