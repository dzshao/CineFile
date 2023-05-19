#include "include/userinterface.h"

using std::cin;
using std::cout;
using std::endl;

void UserInterface::printMainMenu() {
    cout << "Welcome to Cinefile! We will recommend up to 10 movies based on the keywords you enter." << endl;  
    cout << "We can recommend movies based on multiple categories:" << endl;
    cout << "titles (T), genres (G), directors (D), and actors (A)" << endl;
    cout << "What would you like to search by? Enter the corresponding category's letter:" << endl;
}

/* void UserInterface::printMovieList(std::priority_queue<Movie> &movieList) {
    return;
} */