#ifndef MOVIEREC_H
#define MOVIEREC_H


#include <vector>
#include <string>
#include "moviesDatabase.h"
#include "movie.h"
#include "MovieScore.h"



class MovieRec{
    public:
        // bool compareByScore(const movieScore& movie1, const movieScore& movie2);

        std::vector<Movie> recommend(char ratin, const std::vector<std::string>& genr, const std::vector<std::string> &directr, const std::vector<std::string>& actr);
        //way to interact w/




};
#endif