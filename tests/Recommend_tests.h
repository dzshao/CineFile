#ifndef RECOMMEND_TESTS
#define RECOMMEND_TESTS

#include <gtest/gtest.h>
#include "../header/recommender/MovieRec.h"

TEST(Recommendtests, noerrors){
    vector<string> tactors = {"bob", "fred"};
    vector<string tdirect = {"john"};
    vector<string> tgenre = {"horror", "comedy"};
    char tc = 'H';
    EXPECT_NO_THROW(recommend(tc, tgenre, tdirect, tactors));
}

TEST(Recommendtests, emptyActors){
    vector<string> tactors;
    vector<string tdirect;
    vector<string> tgenre;
    char tc = 'H';
    EXPECT_CALL
}

TEST(Recommendtests, emptyDirectors){
    
}

TEST(Recommendtests, emptyGenres){
    
}