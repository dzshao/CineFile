#ifndef RECOMMEND_TESTS
#define RECOMMEND_TESTS

#include <gtest/gtest.h>
#include "../header/database/MovieRec.h"

TEST(Recommendtests, noerrors){
    Movie randomMovie{"Yellowjackets", "(2021– )", {{"Drama"}, {"Horror"}, {"Mystery"}}, 7.8, {{"N/A"}}, {{"Melanie Lynskey"}, {"Tawny Cypress"}, {"Sophie Nélisse"}, {"Jasmin Savoy Brown"}}};
    MoviesDatabase::addMovie(randomMovie);
    vector<string> tactors = {"Bob", "Fred"};
    vector<string> tdirect = {"John"};
    vector<string> tgenre = {"Horror", "Comedy"};
    char tc = 'A';
    EXPECT_NO_THROW(recommend(tc, tgenre, tdirect, tactors));
}

// TEST(Recommendtests, emptyActors){
//     vector<string> tactors;
//     vector<string tdirect;
//     vector<string> tgenre;
//     char tc = 'H';
//     EXPECT_CALL
// }

// TEST(Recommendtests, emptyDirectors){
    
// }

// TEST(Recommendtests, emptyGenres){
    
// }

#endif