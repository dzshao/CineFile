#ifndef IMDB_PARSER_TESTS
#define IMDB_PARSER_TESTS

#include <gtest/gtest.h>

#include "../header/imdbParser.h"

TEST(imdbParserTest, testHorror) {
    imdbParser horror;
    vector<string> listOfHorroMovies = horror.scrapeGenres({"horror"});
    EXPECT_EQ(listOfHorroMovies.at(0), "Evil Dead Rise");
    EXPECT_EQ(listOfHorroMovies.at(1), "Five Nights at Freddy's");
    EXPECT_EQ(listOfHorroMovies.at(2), "From");
    EXPECT_EQ(listOfHorroMovies.at(3), "Yellowjackets");
}

TEST(imdbParserTest, testRomance) {
    imdbParser horror;
    vector<string> listOfHorroMovies = horror.scrapeGenres({"romance"});
    EXPECT_EQ(listOfHorroMovies.at(0), "Queen Charlotte: A Bridgerton Story");
    EXPECT_EQ(listOfHorroMovies.at(1), "The Little Mermaid");
    EXPECT_EQ(listOfHorroMovies.at(2), "Poor Things");
    EXPECT_EQ(listOfHorroMovies.at(3), "Grey's Anatomy");
}

TEST(imdbParserTest, testTwoGenres) {
    imdbParser horror;
    vector<string> listOfHorroMovies = horror.scrapeGenres({"romance", "horror"});
    EXPECT_EQ(listOfHorroMovies.at(0), "Queen Charlotte: A Bridgerton Story");
    EXPECT_EQ(listOfHorroMovies.at(1), "The Little Mermaid");
    EXPECT_EQ(listOfHorroMovies.at(2), "Poor Things");
    EXPECT_EQ(listOfHorroMovies.at(3), "Grey's Anatomy");
    EXPECT_EQ(listOfHorroMovies.at(10), "Evil Dead Rise");
    EXPECT_EQ(listOfHorroMovies.at(11), "Five Nights at Freddy's");
    EXPECT_EQ(listOfHorroMovies.at(12), "From");
    EXPECT_EQ(listOfHorroMovies.at(13), "Yellowjackets");
}

TEST(imdbParserTest, testInvalidGenre) {
    testing::internal::CaptureStdout();
    imdbParser horror;
    vector<string> listOfHorroMovies = horror.scrapeGenres({"bogusGenre"});
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Please enter a valid genre. (bogusGenre is not a valid genre)\n");
}

TEST(imdbParserTest, testTwoInvalidGenre) {
    testing::internal::CaptureStdout();
    imdbParser horror;
    vector<string> listOfHorroMovies = horror.scrapeGenres({"bogusGenre", "bogusGenre2"});
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Please enter a valid genre. (bogusGenre is not a valid genre)\nPlease enter a valid genre. (bogusGenre2 is not a valid genre)\n");
}

TEST(imdbParserTest, testOneInvalidGenreOneValid) {
    testing::internal::CaptureStdout();
    imdbParser horror;
    vector<string> listOfHorroMovies = horror.scrapeGenres({"bogusGenre", "horror"});
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Please enter a valid genre. (bogusGenre is not a valid genre)\n");
    EXPECT_EQ(listOfHorroMovies.at(0), "Evil Dead Rise");
    EXPECT_EQ(listOfHorroMovies.at(1), "Five Nights at Freddy's");
    EXPECT_EQ(listOfHorroMovies.at(2), "From");
    EXPECT_EQ(listOfHorroMovies.at(3), "Yellowjackets");
}

#endif