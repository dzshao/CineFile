#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "person.h"
#include "genre.h"

using std::string;

class Director : public Person {
    public:
        Director() : Person() 
        {};

        Director(std::string _name) : Person(_name) 
        {};

        Director(std::string _name, const std::vector<std::string>&movieList) : 
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