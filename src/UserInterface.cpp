#include "../header/interface/userinterface.h"
#include <iostream>

using namespace std;

char UserInterface::getCharInput() {
    string input;
    getline(cin, input);

    char output = input[0];
    return toupper(output);
}

void UserInterface::printWelcomeMessage() {
    cout << "Welcome to Cinefile! We will recommend up to 10 movies based on keywords you enter." << endl; 
}

void UserInterface::printKeywordInstructions() {
    cout << "We're going to ask you for the names of genres, actors, and directors to act as keywords." << endl;
    cout << "We'll then take those keywords and find movies related to them." << endl;
    cout << "If you do not want to input all 5 keywords for a group, input 'finished' as a keyword when you are done." << endl;
    cout << "If you do not put in any keywords, we will just show you random movies within your rating range." << endl;
}

//Returns a vector of keywords which will be passed into the MovieRecommender class.
void UserInterface::getSearchKeywords(vector<string>& keywords) { 

    //Initialization
    keywords.clear();
    string keyword;

    //Get 5 or fewer keywords.
    unsigned counter = 0;
    do {
        keyword.clear();
        getKeyword(keyword);

        if (keyword.empty()) {
            continue;
        }
        else if (keyword == "Finished") {
            break;
        }
        else {
            keywords.push_back(keyword);
            counter++;
        }
    } while (counter < 5);

    return;
}



//Returns an input string converted to all lowercase as a 'keyword' for UserInterface::getSearchKeywords()

void UserInterface::getKeyword(string& keyword) {
    cout << "Input your keyword and press enter: ";
    getline(cin, keyword);
    cout << endl;
    keyword[0] = toupper(keyword[0]);
    for (unsigned i = 1; i < keyword.length(); ++i) {
        if(keyword[i-1] == '-' || keyword[i-1] == ' '){
            keyword[i] = toupper(keyword[i]);
        } else {
            keyword[i] = tolower(keyword[i]);
        }
    }

    return;
}


void UserInterface::printKeywords(vector<string>& keywords) {
    if (keywords.empty()) {
        cout << "you didn't input any keywords." << endl;
    }
    else {
        cout << "you input keyword(s): ";

        for (unsigned i = 0; i < keywords.size(); ++i) {
            if (i == keywords.size() - 1) {
                cout << keywords.at(i) << endl;
            }
            else {
                cout << keywords.at(i) << ", ";
            }
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

//loops until a valid input character is entered (H, A, or P). Returns the valid input char.
char UserInterface::getLoopExitInput() {

    //init variables for valid input loop
    char output = 'Z';
    bool validInput = false;

    do {
        cout << "If you wish to exit, enter Y. If you want to get another set of movie recommendations, enter N." << endl;
        
        output = getCharInput();
        
        if (output == 'Y' || output == 'N') {
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

void UserInterface::printMovieList(std::vector<Movie> &movieList) {
    cout << "Here's your list of movie recommendations: " << endl << endl;

    for (unsigned i = 0; i < movieList.size(); ++i) {
        cout << i + 1 << ". " << movieList[i] << endl << endl;
    }
}