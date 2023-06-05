#ifndef IMDB_PARSER_TESTS
#define IMDB_PARSER_TESTS

#include <gtest/gtest.h>

#include "../header/webscraping/imdbParser.h"

TEST(imdbParserTest, testHorror) {
    vector<string> listOfHorrorMovies = imdbParser::scrapeGenres({"horror"});
    EXPECT_EQ(listOfHorrorMovies.at(0), "Yellowjackets");
    EXPECT_EQ(listOfHorrorMovies.at(1), "From");
    EXPECT_EQ(listOfHorrorMovies.at(2), "The Boogeyman");
    EXPECT_EQ(listOfHorrorMovies.at(3), "The Walking Dead");
}

TEST(imdbParserTest, testRomance) {
    vector<string> listOfRomanceMovies = imdbParser::scrapeGenres({"romance"});
    EXPECT_EQ(listOfRomanceMovies.at(0), "The Little Mermaid");
    EXPECT_EQ(listOfRomanceMovies.at(1), "Barbie");
    EXPECT_EQ(listOfRomanceMovies.at(2), "Asteroid City");
    EXPECT_EQ(listOfRomanceMovies.at(3), "Queen Charlotte: A Bridgerton Story");
}

TEST(imdbParserTest, testTwoGenres) {
    vector<string> listOfHorrorRomanceMovies = imdbParser::scrapeGenres({"romance", "horror"});
    EXPECT_EQ(listOfHorrorRomanceMovies.at(0), "The Little Mermaid");
    EXPECT_EQ(listOfHorrorRomanceMovies.at(1), "Barbie");
    EXPECT_EQ(listOfHorrorRomanceMovies.at(2), "Asteroid City");
    EXPECT_EQ(listOfHorrorRomanceMovies.at(3), "Queen Charlotte: A Bridgerton Story");
    EXPECT_EQ(listOfHorrorRomanceMovies.at(10), "Yellowjackets");
    EXPECT_EQ(listOfHorrorRomanceMovies.at(11), "From");
    EXPECT_EQ(listOfHorrorRomanceMovies.at(12), "The Boogeyman");
    EXPECT_EQ(listOfHorrorRomanceMovies.at(13), "The Walking Dead");
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
    EXPECT_EQ(listOfHorrorBogusMovies.at(0), "Yellowjackets");
    EXPECT_EQ(listOfHorrorBogusMovies.at(1), "From");
    EXPECT_EQ(listOfHorrorBogusMovies.at(2), "The Boogeyman");
    EXPECT_EQ(listOfHorrorBogusMovies.at(3), "The Walking Dead");
}

#endif
