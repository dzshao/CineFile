#ifndef MOVIESCORE_H
#define MOVIESCORE_H


#include <string>

class movieScore{
    private:
        string mtitle;
        int score;
    public:
        movieScore(string t);
        movieScore();
        int getScore();
        string getTitle();
        void changeScore(int change);


}