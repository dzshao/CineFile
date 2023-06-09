#include "../header/recommender/MovieScore.h"

using namespace std;

movieScore::movieScore(string t){
            title = t;
            score = rand() % 5 + 16;
}

movieScore::movieScore(){
            score = 0;
            mtitle = "";
}

int movieScore::getScore(){
    return this->score;
}

string movieScore::getTitle(){
    return this->title;
}

void movieScore::changeScore(int change){
    score = score + change;

} 