#include "include/userinterface.h"
#include <iostream>

using namespace std;

char UserInterface::getCharInput() {
    char input;
    cin >> input;
    return toupper(input);
}

void UserInterface::printWelcomeMessage() {
    cout << "Welcome to Cinefile! We will recommend up to 10 movies based on up to 10 keywords you enter." << endl; 
}

char UserInterface::getSearchType() { 
    cout << "We can recommend movies based on multiple categories:" << endl;
    cout << "titles (T), genres (G), directors (D), and actors (A)" << endl;
    cout << "What would you like to search by? Enter the corresponding category's letter:" << endl;
    return getCharInput();
}

char UserInterface::getRatingsType() {
    cout << "First, are you looking for movies which are highly rated (H), average rated (A), or poorly rated (P)? Please enter the corresponding letter." << endl;
    return getCharInput();
}

void UserInterface::printMovieList(std::priority_queue<Movie> &movieList) {
    return;
}