//sorting algorithm file

//so user puts in 10 keywords, algo then looks for movies in the database that match it

//so each movie will have a repository of keywords, will loop through entire movie database and see how many keywords match per movie

//takes the first keyword, sees if it matches

//loop through movie list

//for movie[genre] if it matches, reccomend++

//for movie[director] if it matches, reccomend++

//for movie[genres] if it matches, reccomend++

//for movie[ratings] if it falls within ratings band, reccomend++

// so movie storage will look like this: 
// Movie: Title: ejisdfji Rating: sdjwjidw ReleaseYear: 2321 Director: fejifejif Actor: eijefiejf Actor: asdhwi Actor: asodijs Genre: asiodjwio Genre: diasjod


#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

//thhis is assuming a constructor will be made 

void setTitle(const string& ntitle) {
    // movie title = ntitle;
}

void addActor(const string& actor) {
    //movie actors.push_back(actor);
}

void setRating(double rating){
    if(rating < 5){
        //movie rating = BAD;
    } else if (rating >= 5 && rating <= 8){
        //movie rating = AVG;
    } else if (rating > 8){
        //movie rating = GOOD;
    }
}

void actorCompare(const string& act1, const string& act2) {
    cout << "Comparing actors: " << act1 << " and " << act2 << endl;
    if (act1 == act2){
        //movie reccomend++ (find some way to ignore upper/lowercasing)
    }
}

void genreCompare(const string& gen1, const string& gen2) {
    if(gen1 == gen2){
        //movie reccomend++
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

}

int main() {
    ifstream inputFile("MovieDB.txt"); 
    string line;
    if (!inputFile) {
        cout << "Failed to open the file." << endl;
        return 1;
    }

    while (getline(inputFile, line)) {
        istringstream iss(line);
        string word;
        while (iss >> word) {
            if (word == "Movie:"){
                string movieTitle;
                if (iss >> movieTitle){
                    //movie setTitle(iss);
                }
            } else if (word == "Actor:") {
                string currentActor;
                if (iss >> currentActor) {
                    actorCompare(currentActor, previousActor); // Call actorCompare function
                }
            } else if (word == "Genre:") {
                string currentGenre;
                if (iss >> currentGenre){
                    genreCompare(currentGenre, previousGenre);
                }
            } else if (word == "Director:"){
                string currentDirector;
                if (iss >> currentGenre){
                    genreCompare(currentDirector, previousDirector);
                }
            } else if (word == "ReleaseYear:"){
                string currentRelease;
                if (iss >> currentRelease){
                    genreCompare(currentRelease, previousRelease);
                }
            } else if (word == "Rating:"){
                string currentRating;
                if (iss >> currentRating){
                    genreCompare(currentRating, previousRating);
                }
            } 
            cout << word << endl;
        }
    }


}




