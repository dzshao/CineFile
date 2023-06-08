#include "../header/moviesDatabase.h"
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;


void MoviesDatabase::loadMovies(const string&){

}
        
        
        
void MoviesDatabase::addGenre(const genre&){
    allGenres[genre.name] = genre{genre.name, genre.listOfMovies};
}

void MoviesDatabase::addActor(const actor&){
    allActors[actor.name] = actor{actor.name, actor.listOfActors};
}

void MoviesDatabase::addDirector(const director&){
    allDirectors[director.name] = director{director.name, director.listOfActors};
}