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
    void actorCompare(string actor);
    void ratingCompare(string rating);
    void directorCompare(string director);
    void genreCompare(string genre);

    void recommend(vector<string> ratin, vector<string> genr, vector<string> directr, vector<string> actor);
    //way to interact w/




}