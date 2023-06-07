#ifndef PERSON_H
#define PERSON_H

#include <vector>
#include <string>

class Person {
    public:
        Person();

        Person(std::string _name) : 
                name(_name)
        {};

        Person(std::string _name, const std::vector<std::string>&movieList) : 
                name(_name), 
                movies(movieList)
        {};

        std::vector<std::string>& getMovieList() const;
        std::string getName() const;

    protected:
        std::vector<std::string> movies;
        std::string name;
};

#endif