#ifndef IMDB_PARSER_TESTS
#define IMDB_PARSER_TESTS

#include <gtest/gtest.h>

#include "../header/imdbParser.h"

TEST(imdbParserTest, testHorror) {
    vector<string> listOfHorrorMovies = imdbParser::scrapeGenres({"horror"});
    EXPECT_EQ(listOfHorrorMovies.at(0), "From");
    EXPECT_EQ(listOfHorrorMovies.at(1), "Yellowjackets");
    EXPECT_EQ(listOfHorrorMovies.at(2), "Evil Dead Rise");
    EXPECT_EQ(listOfHorrorMovies.at(3), "Five Nights at Freddy's");
}

TEST(imdbParserTest, testRomance) {
    vector<string> listOfRomanceMovies = imdbParser::scrapeGenres({"romance"});
    EXPECT_EQ(listOfRomanceMovies.at(0), "The Little Mermaid");
    EXPECT_EQ(listOfRomanceMovies.at(1), "XO, Kitty");
    EXPECT_EQ(listOfRomanceMovies.at(2), "Queen Charlotte: A Bridgerton Story");
    EXPECT_EQ(listOfRomanceMovies.at(3), "Barbie");
}

TEST(imdbParserTest, testTwoGenres) {
    vector<string> listOfHorrorRomanceMovies =imdbParser::scrapeGenres({"romance", "horror"});
    EXPECT_EQ(listOfHorrorRomanceMovies.at(0), "The Little Mermaid");
    EXPECT_EQ(listOfHorrorRomanceMovies.at(1), "XO, Kitty");
    EXPECT_EQ(listOfHorrorRomanceMovies.at(2), "Queen Charlotte: A Bridgerton Story");
    EXPECT_EQ(listOfHorrorRomanceMovies.at(3), "Barbie");
    EXPECT_EQ(listOfHorrorRomanceMovies.at(10), "From");
    EXPECT_EQ(listOfHorrorRomanceMovies.at(11), "Yellowjackets");
    EXPECT_EQ(listOfHorrorRomanceMovies.at(12), "Evil Dead Rise");
    EXPECT_EQ(listOfHorrorRomanceMovies.at(13), "Five Nights at Freddy's");
}

TEST(imdbParserTest, testInvalidGenre) {
    testing::internal::CaptureStdout();
    vector<string> listOfBogusMovies = imdbParser::scrapeGenres({"bogusGenre"});
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Please enter a valid genre. (bogusGenre is not a valid genre)\n");
}

TEST(imdbParserTest, testTwoInvalidGenre) {
    testing::internal::CaptureStdout();
    vector<string> listOfBogusMovies = imdbParser::scrapeGenres({"bogusGenre", "bogusGenre2"});
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Please enter a valid genre. (bogusGenre is not a valid genre)\nPlease enter a valid genre. (bogusGenre2 is not a valid genre)\n");
}

TEST(imdbParserTest, testOneInvalidGenreOneValid) {
    testing::internal::CaptureStdout();
    vector<string> listOfHorrorBogusMovies = imdbParser::scrapeGenres({"bogusGenre", "horror"});
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Please enter a valid genre. (bogusGenre is not a valid genre)\n");
    EXPECT_EQ(listOfHorrorBogusMovies.at(0), "From");
    EXPECT_EQ(listOfHorrorBogusMovies.at(1), "Yellowjackets");
    EXPECT_EQ(listOfHorrorBogusMovies.at(2), "Evil Dead Rise");
    EXPECT_EQ(listOfHorrorBogusMovies.at(3), "Five Nights at Freddy's");
}

#endif
