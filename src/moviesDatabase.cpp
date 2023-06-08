#include "../header/moviesDatabase.h"
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;


// void MoviesDatabase::loadMovies(const string&){

// }
        
        
        
void MoviesDatabase::addGenre(const genre&){
    allGenres[genre.getName()] = genre
}

void MoviesDatabase::addActor(const actor&){
    allActors[actor.getName()] = actor
}

void MoviesDatabase::addDirector(const director&){
    allDirectors[director.getName()] = director;
}

genre MoviesDatabase::getGenre(string gName){
    return allGenres[gName];
}

actor MoviesDatabase::getActor(string aName){
    return allActors[aName];
}

director MoviesDatabase::getDirector(string dName){
    return allDirectors[dName];
}