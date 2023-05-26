#ifndef IMDB_PARSER_TESTS
#define IMDB_PARSER_TESTS

#include <gtest/gtest.h>

#include "../header/imdbParser.h"

TEST(imdbParserTest, testHorror) {
    imdbParser horror;
    vector<string> listOfHorrorMovies = horror.scrapeGenres({"horror"});
    EXPECT_EQ(listOfHorrorMovies.at(0), "Evil Dead Rise");
    EXPECT_EQ(listOfHorrorMovies.at(1), "Five Nights at Freddy's");
    EXPECT_EQ(listOfHorrorMovies.at(2), "From");
    EXPECT_EQ(listOfHorrorMovies.at(3), "Yellowjackets");
}

TEST(imdbParserTest, testRomance) {
    imdbParser romance
    vector<string> listOfRomanceMovies = romance.scrapeGenres({"romance"});
    EXPECT_EQ(listOfRomanceMovies.at(0), "Queen Charlotte: A Bridgerton Story");
    EXPECT_EQ(listOfRomanceMovies.at(1), "The Little Mermaid");
    EXPECT_EQ(listOfRomanceMovies.at(2), "Poor Things");
    EXPECT_EQ(listOfRomanceMovies.at(3), "Grey's Anatomy");
}

TEST(imdbParserTest, testTwoGenres) {
    imdbParser horrorRomance;
    vector<string> listOfHorrorRomanceMovies = horrorRomance.scrapeGenres({"romance", "horror"});
    EXPECT_EQ(listOfHorrorRomanceMovies.at(0), "Queen Charlotte: A Bridgerton Story");
    EXPECT_EQ(listOfHorrorRomanceMovies.at(1), "The Little Mermaid");
    EXPECT_EQ(listOfHorrorRomanceMovies.at(2), "Poor Things");
    EXPECT_EQ(listOfHorrorRomanceMovies.at(3), "Grey's Anatomy");
    EXPECT_EQ(listOfHorrorRomanceMovies.at(10), "Evil Dead Rise");
    EXPECT_EQ(listOfHorrorRomanceMovies.at(11), "Five Nights at Freddy's");
    EXPECT_EQ(listOfHorrorRomanceMovies.at(12), "From");
    EXPECT_EQ(listOfHorrorRomanceMovies.at(13), "Yellowjackets");
}

TEST(imdbParserTest, testInvalidGenre) {
    testing::internal::CaptureStdout();
    imdbParser bogus;
    vector<string> listOfBogusMovies = bogus.scrapeGenres({"bogusGenre"});
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Please enter a valid genre. (bogusGenre is not a valid genre)\n");
}

TEST(imdbParserTest, testTwoInvalidGenre) {
    testing::internal::CaptureStdout();
    imdbParser boguses;
    vector<string> listOfBogusMovies = boguses.scrapeGenres({"bogusGenre", "bogusGenre2"});
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Please enter a valid genre. (bogusGenre is not a valid genre)\nPlease enter a valid genre. (bogusGenre2 is not a valid genre)\n");
}

TEST(imdbParserTest, testOneInvalidGenreOneValid) {
    testing::internal::CaptureStdout();
    imdbParser horrorBogus;
    vector<string> listOfHorrorBogusMovies = horrorBogus.scrapeGenres({"bogusGenre", "horror"});
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Please enter a valid genre. (bogusGenre is not a valid genre)\n");
    EXPECT_EQ(listOfHorrorBogusMovies.at(0), "Evil Dead Rise");
    EXPECT_EQ(listOfHorrorBogusMovies.at(1), "Five Nights at Freddy's");
    EXPECT_EQ(listOfHorrorBogusMovies.at(2), "From");
    EXPECT_EQ(listOfHorrorBogusMovies.at(3), "Yellowjackets");
}

#endif
