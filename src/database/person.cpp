#include "../../header/database/person.h"

std::string Person::getName() const {
    return name;
}

void Person::setName(const string& newName) {
    name = newName;
};