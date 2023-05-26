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
    interface.printRatingsType(ratings);
    cout << endl;
    //Prompt for recommendation keywords
    vector<string> keywords;
    interface.getSearchKeywords(keywords);
    interface.printKeywords(keywords);
    
    return 0;
}