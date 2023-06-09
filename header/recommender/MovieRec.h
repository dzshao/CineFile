#ifndef MOVIEREC_H
#define MOVIEREC_H

#include "../header/recommender/MovieScore.h"
#include "../header/database/moviesDatabase.h"

struct comparescore {
    bool operator()(MovieScore const & p1, MovieScore const & p2) {
        // return "true" if "p1" is ordered before "p2", for example:
        return p1.score < p2.score;
    }
    };

class MovieRec{
    public:

    vector<Movie>& recommend(char h, vector<string> genr, vector<string> directr, vector<string> actr);
    //way to interact w/




}
#endif