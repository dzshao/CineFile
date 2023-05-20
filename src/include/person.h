#ifndef PERSON_H
#define PERSON_H

class Person {
    protected:
        std::set<std::string> movies;
    public:
        std::set<std::string>& getMovieList();
};

#endif