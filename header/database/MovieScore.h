#ifndef MOVIESCORE_H
#define MOVIESCORE_H


#include <string>

using std::string;

// struct comparescore {
//     bool operator()(MovieScore const & p1, MovieScore const & p2) {
//         // return "true" if "p1" is ordered before "p2", for example:
//         return p1.getScore() < p2.getScore();
//     }
//     };

class movieScore{
    private:
        
        
    public:
        movieScore(string t);
        int getScore();
        string getTitle();
        void changeScore(int change);
        int score;
        std::string title;
        


};
#endif