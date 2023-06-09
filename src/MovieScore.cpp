#include ""../header/recommender/MovieScore.h""

using namespace std;

MovieScore::movieScore(string t){
            title = t;
            score = rand() % 5 + 16;
}

MovieScore::movieScore(){
            score = 0;
            mtitle = "";
}

int MovieScore::getScore(){
    return this->score;
}

string MovieScore::getTitle(){
    return this->title;
}

void MovieScore::changeScore(int change){
    this->score = this->score + change;

} 