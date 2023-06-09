#include "../../header/database/moviesDatabase.h"
#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

std::unordered_map<string, Genre> MoviesDatabase::allGenres;
std::unordered_map<string, Actor> MoviesDatabase::allActors;
std::unordered_map<string, Director> MoviesDatabase::allDirectors; 
std::unordered_map<string, Movie> MoviesDatabase::allMovies;
        
void MoviesDatabase::addGenre(const Genre& genre){
    MoviesDatabase::allGenres[genre.getName()] = genre;
}

void MoviesDatabase::addActor(const Actor& actor){
    MoviesDatabase::allActors[actor.getName()] = actor;
}

void MoviesDatabase::addDirector(const Director& director){
    MoviesDatabase::allDirectors[director.getName()] = director;
}

void MoviesDatabase::addMovie(const Movie& movie){
    MoviesDatabase::allMovies[movie.name] = movie;
}

Genre& MoviesDatabase::getGenre(const string& gName) {
    return MoviesDatabase::allGenres[gName];
}

Actor& MoviesDatabase::getActor(const string& aName) {
    return MoviesDatabase::allActors[aName];
}

Director& MoviesDatabase::getDirector(const string& dName) {
    return MoviesDatabase::allDirectors[dName];
}

Movie& MoviesDatabase::getMovie(const string& mName) {
    return MoviesDatabase::allMovies[mName];
}

std::unordered_map<string, Movie>& MoviesDatabase::getMovieList() {
    return MoviesDatabase::allMovies;
}

std::unordered_map<string, Genre>&  MoviesDatabase::getGenreList() {
    return MoviesDatabase::allGenres;
}

std::unordered_map<string, Director>&  MoviesDatabase::getDirectorList() {
    return MoviesDatabase::allDirectors;
}

std::unordered_map<string, Actor>&  MoviesDatabase::getActorList() {
    return MoviesDatabase::allActors;
}