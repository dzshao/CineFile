#ifndef MOVIEREC_H
#define MOVIEREC_H

//#include <Movie.h>

struct compScore{
    bool operator()(MovieScore const & lmov, MovieScore const & rmov){
        return lmov.getScore() > rmov.getScore();
    }
}

class MovieRec{
    public:

    vector<Movie> recommend(vector<string> ratin, vector<string> genr, vector<string> directr, vector<string> actor);
    //way to interact w/




}