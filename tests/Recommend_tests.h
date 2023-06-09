#ifndef RECOMMEND_TESTS
#define RECOMMEND_TESTS


#include <vector>
#include <gtest/gtest.h>
#include "../header/database/MovieRec.h"

TEST(Recommendtests, noerrors){
    Movie randomMovie{"Yellowjackets", "(2021– )", {{"Drama"}, {"Horror"}, {"Mystery"}}, 7.8, {{"N/A"}}, {{"Melanie Lynskey"}, {"Tawny Cypress"}, {"Sophie Nélisse"}, {"Jasmin Savoy Brown"}}};
    MoviesDatabase::addMovie(randomMovie);
    std::vector<string> tactors = {"Bob", "Fred"};
    std::vector<string> tdirect = {"John"};
    std::vector<string> tgenre = {"Horror", "Comedy"};
    char tc = 'A';
    EXPECT_NO_THROW(MovieRec::recommend(tc, tgenre, tdirect, tactors));
}

TEST(Recommendtests, noerrors2){
    Movie randomMovie{"Yellowjackets", "(2021– )", {{"Drama"}, {"Horror"}, {"Mystery"}}, 7.8, {{"N/A"}}, {{"Melanie Lynskey"}, {"Tawny Cypress"}, {"Sophie Nélisse"}, {"Jasmin Savoy Brown"}}};
    MoviesDatabase::addMovie(randomMovie);
    std::vector<string> tactors = {"Bob", "Fred"};
    std::vector<string> tdirect = {"John", "Alex"};
    std::vector<string> tgenre = {"Horror", "Comedy"};
    char tc = 'A';
    EXPECT_NO_THROW(MovieRec::recommend(tc, tgenre, tdirect, tactors));
}

TEST(Recommendtests, doesitrun){
    Movie randomMovie{"Yellowjackets", "(2021– )", {{"Drama"}, {"Horror"}, {"Mystery"}}, 7.8, {{"N/A"}}, {{"Melanie Lynskey"}, {"Tawny Cypress"}, {"Sophie Nélisse"}, {"Jasmin Savoy Brown"}}};
    MoviesDatabase::addMovie(randomMovie);
    std::vector<string> tactors = {"Bob", "Fred"};
    std::vector<string> tdirect = {"John", "Alex"};
    std::vector<string> tgenre = {"Horror", "Drama"};
    char tc = 'A';
    vector<Movie> testvec = MovieRec::recommend(tc, tgenre, tdirect, tactors);
    EXPECT_EQ(testvec[0].name, "Alien");
}

TEST(Recommendtests, doesitrun){
    Movie randomMovie{"Yellowjackets", "(2021– )", {{"Drama"}, {"Horror"}, {"Mystery"}}, 7.8, {{"N/A"}}, {{"Melanie Lynskey"}, {"Tawny Cypress"}, {"Sophie Nélisse"}, {"Jasmin Savoy Brown"}}};
    MoviesDatabase::addMovie(randomMovie);
    std::vector<string> tactors = {"Morgan Freeman", "Fred"};
    std::vector<string> tdirect = {"John", "Alex"};
    std::vector<string> tgenre = {"Horror", "Drama"};
    char tc = 'A';
    vector<Movie> testvec = MovieRec::recommend(tc, tgenre, tdirect, tactors);
    EXPECT_EQ(testvec[0].name, "Alien");
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