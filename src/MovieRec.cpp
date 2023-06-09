//sorting algorithm file

//so user puts in 10 keywords, algo then looks for movies in the database that match it

//so each movie will have a repository of keywords, will loop through entire movie database and see how many keywords match per movie

//takes the first keyword, sees if it matches

//loop through movie list

//for movie[genre] if it matches, reccomend++

//for movie[director] if it matches, reccomend++

//for movie[genres] if it matches, reccomend++

//for movie[ratings] if it falls within ratings band, reccomend++

//at the end it'll reccomend you the movie with the highest reccomend scores, if movie is tied for recommend scores
//it will recommend a random one

// so movie storage will look like this: 
// Movie: Title: ejisdfji Rating: sdjwjidw ReleaseYear: 2321 Director: fejifejif Actor: eijefiejf Actor: asdhwi Actor: asodijs Genre: asiodjwio Genre: diasjod

//create a new movie class, passing in the 

//remember to include moviescore

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <#include "../header/recommender/MovieScore.h">
//include movie.h wherever that is

using namespace std;

//will i be parsing a massive array of movie objects?

//thhis is assuming a constructor will be made 

// movieRecommend class()
// itll have all these functions, mainly setters, getters, and comparers. 
// input words from interface should be stored by their category
// create an array of strings, for each one in array we must compare
// rating to string converter should happen here or elsewhere?
// will have score, 




// 

//then return top 10 values of priority queue


// void setTitle(const string& ntitle) {
//     // movie title = ntitle;
// }

// void addActor(const string& actor) {
//     //movie actors.push_back(actor);
// }

//build convertrating into the movie class/datareader

//Movierecommend has 2 variables: movie object and score
//
//constructor
vector<Movie>& MovieRec::recommend(vector<string> ratin, vector<string> genr, vector<string> directr, vector<string> actr){

    movieDatabase movieDB;

    vector<Movie> movieStore;

    priority_queue<MovieScore, vector<MovieScore>, compScore> pq;
    
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
            for(MovieScore sloop : pq){ //for every moviescore object in pq
                if(sloop.getTitle() == tempTitle){ //if the moviescore object have same title as movieobject
                    doesContain = true;
                    sloop.changeScore(22); //increases score and makes sure it wont create new object
                }
            } if (doesContain == false){ //if same title not found
                pq.push_back(MovieScore(tempTitle)); //creates new moviescore object of that title and scores it
            }
        }
        //compare by setting tolower(), might need to set all of movie objects info to lower
        //then store all that match into a vector/list
        //might need to delete moviestore to free mem

    }
    for(auto&& item : directr){ //for every director typed
        Director newdirect = movieDB.getDirector(item); //gets the director object which stores every movie with x director
        set<string> dMov = newdirect.getMovieList(); // gets the set of movie titles
        
        for(auto e : dMov){ //for every movie in dmov

            string tempTitle = e; //sets temp title to the movie's name
            // if pq does not contain any movies with same title as current movie, create new
            // if one does match, increase its score by like 22
            bool doesContain = false;
            for(MovieScore sloop : pq){ //for every moviescore object in pq
                if(sloop.getTitle() == tempTitle){ //if the moviescore object have same title as movieobject
                    doesContain = true;
                    sloop.changeScore(22); //increases score and makes sure it wont create new object
                }
            } if (doesContain == false){ //if same title not found
                pq.push_back(MovieScore(tempTitle)); //creates new moviescore object of that title and scores it
            }
        }
        //compare by setting tolower(), might need to set all of movie objects info to lower
        //then store all that match into a vector/list
        //might need to delete moviestore to free mem


        
    }
    for(auto&& item : actr){
        Actor newact = movieDB.getActor(item); //gets the actor object which stores every movie with x actor
        set<string> aMov = newact.getMovieList(); // gets the set of movie titles
        
        for(auto e : aMov){ //for every movie in dmov

            string tempTitle = e; //sets temp title to the movie's name
            // if pq does not contain any movies with same title as current movie, create new
            // if one does match, increase its score by like 22
            bool doesContain = false;
            for(MovieScore sloop : pq){ //for every moviescore object in pq
                if(sloop.getTitle() == tempTitle){ //if the moviescore object have same title as movieobject
                    doesContain = true;
                    sloop.changeScore(22); //increases score and makes sure it wont create new object
                }
            } if (doesContain == false){ //if same title not found
                pq.push_back(MovieScore(tempTitle)); //creates new moviescore object of that title and scores it
            }
        }
        //compare by setting tolower(), might need to set all of movie objects info to lower
        //then store all that match into a vector/list
        //might need to delete moviestore to free mem

    }

    //after the list has been assigned score to, use getters to get the top 10 movies with getTitle() or whatever and then return a priority queue wit them
    //output top then pop 10 times
    vector<Movie> fq;

    for(int i = 0; i < 10; i++){
        string tTitle = pq.top().getTitle();
        Movie nMovie = movieDB.getMovie(tTitle);
        fq.push_back(nMovie);
        pq.pop();
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

