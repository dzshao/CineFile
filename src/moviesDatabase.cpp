#include "../header/moviesDatabase.h"
#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>

using namespace std;

//reads in file
//Still working on
void MoviesDatabase::loadMovies(){
    ifstream inFS;     
   
   cout << "Opening file" << endl;

   inFS.open("movies.txt");//or whatever the file name will be
   if (!inFS.is_open()) {
      cout << "Could not open file movies.txt." << endl;
      return 1; 
   }

   /
   cout << "Reading movies" << endl;
   inFS >> movieInfo
   while(!inFS.fail()){


   }
   cout << "Closing file movie.txt." << endl;
   inFS.close(); // Done with file, so close it

   


}

//puts info on a file
void MoviesDatabase::storeMovies(){

}
        
        
        
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