#include ""../header/recommender/MovieScore.h""

using namespace std;

movieScore(string t){
            title = t;
            score = rand() % 5 + 16;
}
movieScore(){
            score = 0;
            mtitle = "";
}

int getScore(){
    return this->score;
}

string getTitle(){
    return this->title;
}

void changeScore(int change){
    this->score = this->score + change;

} 