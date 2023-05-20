//Libraries
#include <iostream>
#include <string>
#include <vector>
#include <queue>

//Project headers
#include "include/userinterface.h"

using namespace std;

int main() {

    UserInterface interface;
    //Welcome message
    interface.printWelcomeMessage();

    //Begin program loop (loop not implemented yet)
        //...
    //Prompt for movies' ratings range
    char ratings = interface.getRatingsType();
    cout << ratings << endl; //test to just parrot input
    //Prompt for search type
    char searchType = interface.getSearchType();
    cout << searchType << endl; //test to just parrot input
    
    return 0;
}