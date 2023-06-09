#include "../header/database/MovieScore.h"

using namespace std;

movieScore::movieScore(std::string t){
            title = t;
            score = 1;
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