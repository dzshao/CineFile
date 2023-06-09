#ifndef MOVIEREC_H
#define MOVIEREC_H

#include "../header/recommender/MovieScore.h"
// #include "../header/MoviesDatabase.h"

struct compScore{
    bool operator()(MovieScore const & lmov, MovieScore const & rmov){
        return lmov.getScore() > rmov.getScore();
    }
}

class MovieRec{
    public:

    vector<Movie>& recommend(char, vector<string>, vector<string>, vector<string>);
    //way to interact w/




}