//Libraries
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cassert>

//Project headers
#include "../header/database/moviesDatabase.h"
#include "../header/webscraping/imdbParser.h"
#include "../header/interface/userinterface.h"
#include "../header/database/MovieRec.h"

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
        cout << "You must enter at least 1 genre." << endl;
        vector<string> genresList;
        interface.getSearchKeywords(genresList);

        while(genresList.size() < 1){
            cout << "Please enter at least 1 genre." << endl;
            interface.getSearchKeywords(genresList);
        }


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

        //Scraping movies from imdb
        imdbParser::scrapeGenres(genresList);

        //Get movie recommendations
        vector<Movie> recommendations = MovieRec::recommend(ratingsInput, genresList, directorsList, actorsList);

        //Print movie recommendations        
        interface.printMovieList(recommendations);
        
        //Prompt to exit the program or search again.
        cout << endl;
        exitLoop = interface.getLoopExitInput();

        if (exitLoop == 'Y') {
            cout << "Thank you for using Cinefile!" << endl;
        }

    }
    // Web scraping cleanup
    curl_global_cleanup();
    return 0;
}