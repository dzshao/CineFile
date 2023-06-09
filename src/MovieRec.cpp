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

    MoviesDatabase movieDB;

    vector<Movie> movieStore;

    // priority_queue<MovieScore, vector<MovieScore>, compScore> pq;

    vector<movieScore> movieq;
    
    //movieDB.getRating(ratin); assuming this will populate movieDB with movies of that rating

    for(auto&& item : genr){ //for every string in vector genres
        Genre newgenre = movieDB.getGenre(item); //gets the genre object which stores every movie with x genre
        unordered_map<string, Movie>& genreMap = newgenre.getMovieList(); //creates a Genremap which contains this list of movies
        
        for(const auto& mapp : genreMap){ //for every movie in Genremap
            const Movie& movi = mapp.second; //sets temp movie object to what is mapped
            string tempTitle = movi.name; //sets temp title to the movie's name
            // if pq does not contain any movies with same title as current movie, create new
            // if one does match, increase its score by like 22 or whatever
            bool doesContain = false; //bool to check if movie already in priority q
            for(movieScore lp : movieq){
                if(lp.getTitle() == tempTitle){
                    doesContain = true;
                    lp.changeScore(22);
                }
            } if (doesContain == false){ //if same title not found
                movieq.push_back(movieScore(tempTitle)); //creates new moviescore object of that title and scores it
            }
        }
        //compare by setting tolower(), might need to set all of movie objects info to lower
        //then store all that match into a vector/list
        //might need to delete moviestore to free mem

    }
    for(auto&& item : directr){ //for every director typed
        Director newdirect = movieDB.getDirector(item); //gets the director object which stores every movie with x director
        vector<string> dMov = newdirect.getMovieList(); // gets the set of movie titles
        
        for(auto e : dMov){ //for every movie in dmov

            string tempTitle = e; //sets temp title to the movie's name
            // if pq does not contain any movies with same title as current movie, create new
            // if one does match, increase its score by like 22
            bool doesContain = false;
            for(movieScore sloop : movieq){ //for every moviescore object in pq
                if(sloop.getTitle() == tempTitle){ //if the moviescore object have same title as movieobject
                    doesContain = true;
                    sloop.changeScore(22); //increases score and makes sure it wont create new object
                }
            } if (doesContain == false){ //if same title not found
                movieq.push_back(movieScore(tempTitle)); //creates new moviescore object of that title and scores it
            }
        }
        //compare by setting tolower(), might need to set all of movie objects info to lower
        //then store all that match into a vector/list
        //might need to delete moviestore to free mem


        
    }
    for(auto&& item : actr){
        Actor newact = movieDB.getActor(item); //gets the actor object which stores every movie with x actor
        vector<string> & aMov = newact.getMovieList(); // gets the set of movie titles
        
        for(auto e : aMov){ //for every movie in dmov

            string tempTitle = e; //sets temp title to the movie's name
            // if pq does not contain any movies with same title as current movie, create new
            // if one does match, increase its score by like 22
            bool doesContain = false;
            for(movieScore sloop : movieq){ //for every moviescore object in pq
                if(sloop.getTitle() == tempTitle){ //if the moviescore object have same title as movieobject
                    doesContain = true;
                    sloop.changeScore(22); //increases score and makes sure it wont create new object
                }
            } if (doesContain == false){ //if same title not found
                movieq.push_back(movieScore(tempTitle)); //creates new moviescore object of that title and scores it
            }
        }
        //compare by setting tolower(), might need to set all of movie objects info to lower
        //then store all that match into a vector/list
        //might need to delete moviestore to free mem

    }

    //after the list has been assigned score to, use getters to get the top 10 movies with getTitle() or whatever and then return a priority queue wit them
    //output top then pop 10 times

    //so all movies that qualify have been stored in movieqs

    

    //priority_queue<MovieScore, vector<MovieScore>, comparescore> pq;

   
    vector<Movie> fq;
    
    // for(unsigned int i = 0; i < movieq.size(); i++){

    //     movieScore tm = movieq[i];
    //     if(tm.getScore() < )
    //     pq.push(tm); 

        
    // }

    // sort(movieq.begin(), movieq.end(), compareByScore());

    

    // if(ratin == 'h'|| ratin == 'H'){
    //     for(unsigned int i = 0; i < movieq.size(); i++){
    //         string tt = movieq[i].getTitle();
    //         Movie nm = movieDB.getMovie(tt);
    //         int rt = nm.rating;
    //         if(rt >= 8.0 || rt == 0.0){
    //             pq.push()
    //         }

    //     }
    // }


    // if(ratin == 'h'|| ratin == 'H'){
    //     while(fq.size() < 10){
    //         string tTitle = pq.top().getTitle();
    //         Movie nMovie = movieDB.getMovie(tTitle);
    //         if (nMovie.rating >= 8.0 || nMovie.rating == 0.0){
    //             fq.push_back(nMovie);
    //         }
    //         pq.pop();
    //     }
    // }

    // else if(ratin == 'a'|| ratin == 'A'){
    //     while(fq.size() < 10){
    //         string tTitle = pq.top().getTitle();
    //         Movie nMovie = movieDB.getMovie(tTitle);
    //         if (nMovie.rating < 8.0 && nMovie.rating > 5.0 || nMovie.rating == 0.0){
    //             pq.push(nMovie);
    //             movieq.pop_front()
    //         }
    //         movieq.pop();
    //     }
    // }

    // else if(ratin == 'p'|| ratin == 'P'){
    //     while(fq.size() < 10){
    //         string tTitle = pq.top().getTitle();
    //         Movie nMovie = movieDB.getMovie(tTitle);
    //         if (nMovie.rating <= 5.0 || nMovie.rating == 0.0){
    //             fq.push_back(nMovie);
    //         }
    //         pq.pop();
    //     }
    // }
    

    for(int i = 0; i < 10; i++){
        movieScore tem = movieq[i];
        string tTitle = tem.getTitle();
        Movie nMovie = movieDB.getMovie(tTitle);
        fq.push_back(nMovie);
        
    }

    //delete pq
    
    return fq;
}


//this also needs to recieve keywords that are entered
//entered keywords will be stored in a vector per classification
//each specific compare function will loop through the vector, comparing each keyword to the keyword of the movie, each time it matches the score is increased
//compare functions should only take in 1 string, which is the string being read from the database
//if no keywords match increases score by smaller random amount

//how to convert numbers to high/low ratings?

