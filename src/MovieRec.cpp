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
void setRating(double rating){
    if(rating < 5){
        //movie rating = BAD;
    } else if (rating >= 5 && rating <= 8){
        //movie rating = AVG;
    } else if (rating > 8){
        //movie rating = GOOD;
    }
}

//if previous actor not entered, then skip this function/run actorCompare(string act1)
void actorCompare(const string& act1, const string& act2) {
    cout << "Comparing actors: " << act1 << " and " << act2 << endl;
    if (act1 == act2){
        //movie reccomend++ (find some way to ignore upper/lowercasing)
    } 
    //otherwise increase score by smaller random amount
}

void genreCompare(const string& gen1, const string& gen2) {
    if(gen1 == gen2){
        changeScore(21);

    } else {
        int tempi = rand() % 5 + 15;
        changeScore(tempi);
    }


}

void releaseCompare(const string& rel1, const string& rel2) {
    if(rel1 == rel2){
        //movie reccomend++
    }

}

void ratingCompare(const string& rat1, const string& rat2) {
    if(rat1 == rat2){
        //movie reccomend++
    }
    //look at first char of the rating, if 0/2-4 its a bad movie, if 5-7 its a good movie, 8 9 or 1 its a great movie
    // if close in rating recommend+

}

void directorCompare(const string& dir1, const string& dir2){
    if(dir1 == dir2){
        //movie recommend++
    }

}

void findHighest(vector<int> mlist){
    // finds highest and returns it

}

//Movierecommend has 2 variables: movie object and score
//
//constructor
void recommend(vector<string> ratin, vector<string> genr, vector<string> directr, vector<string> actr){

    
    movieDatabase movieDB;
    vector<Movie> finalten;

    vector<Movie> movieStore;

    priority_queue<MovieScore, vector<MovieScore>, compScore> pq;
    priority_queue<Movie, vector<Movie>, compScore> fq;
    
    movieDB.getRating(ratin); //assuming this will populate movieDB with movies of that rating



    for(auto&& item : genr){ //for every string in vector genres
        unordered_map<string, Genre>& genreMap = movieDB.getGenreList();
        
        //movieStore = movieDB.allGenres(item); //i assume this will return a vector of movies that match the genre(s), stores it in movieStore

        for(auto mov : genreMap){ //for every movie in Genrestore
            string tempTitle = mov.second.name; // assuming getTitle is a function
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
    for(auto&& item : directr){ //for every director typed
       unordered_map<string, Genre>& directMap = movieDB.getDirectorList(); //creates a map of all movies director is in
        
        //movieStore = movieDB.allGenres(item); //i assume this will return a vector of movies that match the genre(s), stores it in movieStore

        for(auto mov : directMap){ //for every movie in directorMap
            string tempTitle = mov.second.name; // set temptitle as name
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
        unordered_map<string, Genre>& directMap = movieDB.getDirectorList();
        
        //movieStore = movieDB.allGenres(item); //i assume this will return a vector of movies that match the genre(s), stores it in movieStore

        for(auto mov : directMap){ //for every movie in Genrestore
            string tempTitle = mov.second.name; // assuming getTitle is a function
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

    //after the list has been assigned score to, use getters to get the top 5 movies with getTitle() or whatever and then return a priority queue wit them
    //output top then pop 10 times
    for(int i = 0; i < 10; i++){
        string tTitle = pq.top().getTitle();
        fq.push_back(movieDB.getMovie(tTitle));
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

int main() {
    ifstream inputFile("MovieDB.txt"); 
    string line;
    if (!inputFile) {
        cout << "Failed to open the file." << endl;
        return 1;
    }
    vector<string> words;
    vector<MovieRecommend*> movies;
    MovieRecommend* currentMovie = nullptr;

    while (getline(inputFile, line)) {
        istringstream iss(line);
        string word;
        while (iss >> word) {
            if (word == "Movie:"){
                if (inputFile >> word) {
                MovieRecommend* newMovie = new MovieRecommend(word);
                movies.push_back(newMovie);

                delete currentMovie; // Delete the previous movie, if any
                currentMovie = newMovie;
                // string movieTitle;
                // if (iss >> movieTitle){
                //     //create new recommendation for MovieTitle
                //     //set movie as the one to be compared to and functions to be applied to
                // }
            } else if (word == "Actor:" && currentMovie != nullptr) {
                string currentActor;
                if (iss >> currentActor) {
                    currentMovie->actorCompare(currentActor); // Call actorCompare function
                    // if actorcompare true add recommendation to current movierecommend
                    // else add random smaller value to recommendation
                }
            } else if (word == "Genre:") {
                string currentGenre;
                if (iss >> currentGenre){
                    currentMovie->genreCompare(currentGenre);
                }
            } else if (word == "Director:"){
                string currentDirector;
                if (iss >> currentGenre){
                    currentMovie->directorCompare(currentDirector);
                }
            } else if (word == "Rating:"){
                string currentRating;
                if (iss >> currentRating){
                    currentMovie->ratingCompare(currentRating);
                }
            } 
            cout << word << endl;
        }
    }
    }

    //function at end that finds the movie with 10 highest scores and returns them
    //loop through vector and check score for each movie searched, create another vector of top 10 movies by keeping track of the top 3 movies
    //the rest of these will be random lol


}




// else if (word == "ReleaseYear:"){
//                 string currentRelease;
//                 if (iss >> currentRelease){
//                     releaseCompare(currentRelease, previousRelease);
//                 }
//             } 


//implementation with getters
//for each movie with 

