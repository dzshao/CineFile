#include "../header/moviesDatabase.h"
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// Simple example Movie struct implementation. 
// This isn't everything the movie struct will have so don't use this as a basis for the actual implementation.


int main() {
    // This map will map keys of type string to Movie objects
    unordered_map<string, Genre> allGenres;
    
    // New keys are added using the [] operator.
    // The key is inside the brackets and the mapped value is what the value is set equal to
    movieMap["Comedy"] = {(whatever is held is genre class)};
   

    return 0;
}