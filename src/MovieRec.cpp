#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_map>

#include "../header/database/MovieRec.h"
#include "../header/database/MovieScore.h"


using namespace std;



// bool MovieRec::compareByScore(const movieScore& movie1, const movieScore& movie2) {
//     return movie1.getScore() > movie2.getScore();
// }

std::vector<Movie> MovieRec::recommend(char ratin, const std::vector<std::string>& genr, const std::vector<std::string> &directr, const std::vector<std::string>& actr){

    //MoviesDatabase movieDB;

    // vector<Movie> movieStore;

    // priority_queue<MovieScore, vector<MovieScore>, compScore> pq;

    vector<movieScore> movieq;
    
    //movieDB.getRating(ratin); assuming this will populate movieDB with movies of that rating

    

    unordered_map<string, Movie>& genreMap = MoviesDatabase::getMovieList(); //creates a Genremap which contains this list of movies
        
    for(const auto& mapp : genreMap){ //for every movie in Genremap
        const Movie& movi = mapp.second; //sets temp movie object to what is mapped
        string tempTitle = movi.name; //sets temp title to the movie's name
        // if pq does not contain any movies with same title as current movie, create new
        bool doesContain = false; //bool to check if movie already in priority q
        for(movieScore lp : movieq){
            if(lp.getTitle() == tempTitle){
                doesContain = true; // if one does match, increase its score 
                lp.changeScore(1);
            }
        } if (doesContain == false){ //if same title not found
            movieq.push_back(movieScore(tempTitle)); //creates new moviescore object of that title and scores it
        }
    }

        

    
    
    if (directr.size() != 0){
    for(auto&& item : directr){ //for every string in directr
        for(movieScore& lp : movieq){ //for every movieScore object
            string tTitle = lp.getTitle(); //set string as temp title
            Movie tmov = MoviesDatabase::getMovie(tTitle); //fetches movie based on title
            
            for(unsigned int i = 0; i < tmov.directorList.size(); i++){ //for every string in directorlist
                Director di = tmov.directorList[i];//temp director object
                if (di.getName() == item){ //if director == the earlier string from user input vector directr
                    lp.changeScore(1); //score++
                }
            }

        }

    }
    }

    if(actr.size() != 0){
    for(auto&& item : actr){ //works same way as directors but with actors instead
        for(movieScore& lp : movieq){
            string tTitle = lp.getTitle();
            Movie tmov = MoviesDatabase::getMovie(tTitle);
            
            for(unsigned int i = 0; i < tmov.castList.size(); i++){
                Actor ac = tmov.castList[i];
                if (ac.getName() == item){
                    lp.changeScore(1);
                }
            }

        }

    }
    }

    vector<Movie> fq;
    vector<movieScore> teq;

    for(unsigned int i = 0; i< movieq.size(); i++){
        movieScore ts = movieq[i];
        if (ts.getScore() >= 3){
            teq.push_back(ts);
        }
    }

    for(unsigned int i = 0; i< movieq.size(); i++){
        movieScore ts = movieq[i];
        if (ts.getScore() == 2){
            teq.push_back(ts);
        }
    }

    for(unsigned int i = 0; i< movieq.size(); i++){
        movieScore ts = movieq[i];
        if (ts.getScore() == 1){
            teq.push_back(ts);
        }
    }

    for(unsigned int i = 0; i < 10; i++){
        movieScore ms = teq[i];
        string st = ms.getTitle();
        Movie mt = MoviesDatabase::getMovie(st);
        fq.push_back(mt);
    }
    return fq;
}
