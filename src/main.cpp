//Libraries
#include <iostream>
#include <string>
#include <vector>
#include <queue>

//Project headers
#include "include/userinterface.h"

using namespace std;

int main() {
    //Initialize interface object.
    UserInterface interface;

    //Begin program loop (to get more recommendations if the user wants to)
    char exitLoop = 'N';

    while (exitLoop != 'Y') {

        interface.printWelcomeMessage();

        //Prompt for input regarding movie recommendation ratings range.
        char ratingsInput = interface.getRatingsType();
        interface.printRatingsType(ratingsInput);
        cout << endl;

        //Begin collection of keyword(s) for recommendation algorithm from user input.
        interface.printKeywordInstructions();
        cout << endl;

        //Get genre keyword(s) from user input.
        cout << "Let's start with genres. Enter up to 5, or enter 'finished' when you are done if you have less than 5." << endl;
        vector<string> genresList;
        interface.getSearchKeywords(genresList);

        //Get director keyword(s) from user input.
        cout << "Now, how about directors? Enter up to 5, or enter 'finished' when you are done if you have less than 5." << endl;
        vector<string> directorsList;
        interface.getSearchKeywords(directorsList);

        //Get actor keyword(s) from user input.
        cout << "Finally, what about actors? Enter up to 5, or enter 'finished' when you are done if you have less than 5." << endl;
        vector<string> actorsList;
        interface.getSearchKeywords(actorsList);

        //Print back the user's input
        cout << "Okay, for genres ";
        interface.printKeywords(genresList);
        cout << "For directors, ";
        interface.printKeywords(directorsList);
        cout << "For actors, ";
        interface.printKeywords(actorsList);
        cout << endl;

        //Generate recommendations
        //MovieRecommender::recommend(ratingsInput, genresList, directorsList, actorsList);

        cout << "Here's your list of movie recommendations: " << endl << endl;

        //Mock recommendations
        cout << "Hereditary (2018):" << endl;
        cout << "Genre(s): Horror, Mystery, Thriller" << endl;
        cout << "Starring: Toni Collette, ALex Wolff, Milly Shapiro" << endl << endl;
        cout << "American Psycho (2000):" << endl;
        cout << "Genre(s): Crime, Drama, Thriller" << endl;
        cout << "Starring: Christian Bale, Willem Dafoe, Jared Leto" << endl << endl;
        cout << "Rushmore (1998):" << endl;
        cout << "Genre(s): Comedy, Drama" << endl;
        cout << "Starring: Jason Schwartzman, Bill Murray, Olivia Williams" << endl;
        

        //Prompt to exit the program or search again.
        cout << endl;
        exitLoop = interface.getLoopExitInput();

        if (exitLoop == 'Y') {
            cout << "Thank you for using Cinefile!" << endl;
        }

    }

    return 0;
}