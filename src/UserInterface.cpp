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

//Returns a vector of keywords which will be passed into the MovieRecommender class.
void UserInterface::getSearchKeywords(vector<string>& keywords) { 
    cout << "We can recommend movies based on up to 10 keywords." << endl;
    cout << "Try entering keywords such as the names of genres, actors, or directors." << endl;
    cout << "We'll take those keywords and find movies related to them." << endl;
    cout << "If you do not want to input 10 keywords, input 'finished' as a keyword when you are done." << endl;
    cout << endl;

    //Initialization
    keywords.clear();
    string keyword;
    cin.ignore();

    //Get 10 or fewer keywords, do while is better here than a for loop becuase of the way continue works.
    unsigned i = 0;
    do {
        keyword.clear();
        getKeyword(keyword);

        if (keyword == "finished" && keywords.empty() == true) {
            cout << "You need at least one keyword." << endl;
            continue;
        }
        else if (keyword == "finished") {
            break;
        }
        else {
            keywords.push_back(keyword);
            i++;
        }
    } while (i < 10);

    return;
}

//Returns an input string converted to all lowercase as a 'keyword' for UserInterface::getSearchKeywords()
void UserInterface::getKeyword(string& keyword) {
    cout << "Input your keyword and press enter: " << endl;
    getline(cin, keyword);

    for (unsigned i = 0; i < keyword.length(); ++i) {
        keyword[i] = tolower(keyword[i]);
    }

    return;
}

void UserInterface::printKeywords(vector<string>& keywords) {
    cout << "You input keyword(s): ";

    for (unsigned i = 0; i < keywords.size(); ++i) {
        if (i == keywords.size() - 1) {
            cout << keywords.at(i) << endl;
        }
        else {
            cout << keywords.at(i) << ", ";
        }
    }
}

//loops until a valid input character is entered (H, A, or P). Returns the valid input char.
char UserInterface::getRatingsType() {

    //init variables for valid input loop
    char output = 'Z';
    bool validInput = false;

    do {
        cout << "First, are you looking for movies which are highly rated (H), average rated (A), or poorly rated (P)? Please enter the corresponding letter." << endl;
        
        output = getCharInput();
        
        if (output == 'H' || output == 'A' || output == 'P') {
            validInput = true;
        }
    } while (!validInput);

    return output;
}

//Prints a message corresponding to the user's input concerning ratings.
//Input should be valid because UserInterface::getRatingsType() handles input validation.
void UserInterface::printRatingsType(char ratings) {
    if (ratings == 'H') {
        cout << "Great! We'll only recommend movies that are highly rated." << endl;
    }
    else if (ratings == 'A') {
        cout << "Alright! We'll only recommend movies that have an average rating." << endl;
    }
    else {
        cout << "Okay. We'll only recommend movies that are poorly rated." << endl;
    }
}

void UserInterface::printMovieList(std::priority_queue<Movie> &movieList) {
    return;
}