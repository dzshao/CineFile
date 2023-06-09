#ifndef PERSON_H
#define PERSON_H

#include <vector>
#include <string>

class Person {
    public:
        Person() : 
                name()
        {};

        Person(std::string _name) : 
                name(_name)
        {};

        std::string getName() const;
        void setName(const std::string&);

    protected:
        std::string name;
};

#endif