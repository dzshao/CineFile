#include "../header/moviesDatabase.h"
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// Simple example Movie struct implementation. 
// This isn't everything the movie struct will have so don't use this as a basis for the actual implementation.
struct Movie {
    Movie() : 
            name();
            rating();
            releaseYear();
    {};

    Movie(string newTitle, double newRating,unsigned newReleaseYear) : 
            name(newName);
            rating(newRating); 
            releaseYear(newReleaseYear);

    {};

    string name;
    double rating;
    unsigned releaseYear;
};

int main() {
    // This map will map keys of type string to Movie objects
    unordered_map<string, Movie> movieMap;
    
    // New keys are added using the [] operator.
    // The key is inside the brackets and the mapped value is what the value is set equal to
    movieMap["Scream VI"] = {"Scream VI", 8.5, 2023};
    movieMap["Everything Everywhere All at Once"] =  {"Everything Everywhere All at Once", 9.5, 2022};

    // Values are indexed using the [] operator again, putting the key into the bracket to get its mapped value
    // For example, movieMap["Scream VI"] will return the Scream VI Movie object, so we can quickly get all the information about Scream VI
    cout << movieMap["Scream VI"].title << "'s Rating: " 
         << movieMap["Scream VI"].rating  << " Year: " <<  movieMap["Scream VI"].releaseYear<< endl;
    
    cout << movieMap["Everything Everywhere All at Once"].title << "'s Rating: " 
         << movieMap["Everything Everywhere All at Once"].rating << " Year: " <<  movieMap["Everything Everywhere All at Once"].releaseYear << endl;

    // Adding a new value
    movieMap["Five Nights at Freddy's"] = {"Five nights at Freddy's", 10.0};

    // Printing out the values of the newly added value
    cout << movieMap["Five Nights at Freddy's"].title << "'s Rating: " 
         << movieMap["Five Nights at Freddy's"].rating << " Year: " <<  movieMap["Five Nights at Freddy's"].releaseYear << endl;
    cout << endl;

    /* We can iterate through unordered maps using iterators. 
    The variable "i" is a pair value that is a pair of <string, Movie>. 
    We're iterating through the map to get all the movies, so we'll take the second value of the pair, the Movie object, using
    the "->second" operator. Then we are given a Movie object and can easily get the values we want from there.
    The order that movies are output will be inconsistent because unordered maps are, well, unordered.
    */
    for (auto i = movieMap.begin(); i != movieMap.end(); i++) {
        cout << (i->second).title << "'s Rating: " 
             << (i->second).rating << endl;
    }

    /* Using a map to map Movie title's to their respective Movie objects allows us to easily find the actual Movie object
    relating to a movie from just its title. Otherwise, we'd have to iterate through our entire list of movies and compare the
    title data member of each Movie object to the movie title we're trying to find. This would take much longer than just using a map. 
    The same applies for the Genre's, we can quickly and efficiently find a Genre object based on its name using a map.*/

    return 0;
}