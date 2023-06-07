#ifndef IMDB_PARSER_TESTS
#define IMDB_PARSER_TESTS

#include <gtest/gtest.h>

#include "../header/webscraping/imdbParser.h"

TEST(imdbParserTest, testHorror) {
    vector<Movie> listOfHorrorMovies = imdbParser::scrapeGenres({"horror"});
    EXPECT_EQ(listOfHorrorMovies.at(0).name, "Yellowjackets");
    EXPECT_EQ(listOfHorrorMovies.at(1).name, "From");
    EXPECT_EQ(listOfHorrorMovies.at(2).name, "The Boogeyman");
    EXPECT_EQ(listOfHorrorMovies.at(3).name, "The Walking Dead");

    EXPECT_EQ(listOfHorrorMovies.at(0).releaseDates, "(2021– )");
    EXPECT_EQ(listOfHorrorMovies.at(1).releaseDates, "(2022– )");
    EXPECT_EQ(listOfHorrorMovies.at(2).releaseDates, "(2023)");
    EXPECT_EQ(listOfHorrorMovies.at(3).releaseDates, "(2010–2022)");
}

TEST(imdbParserTest, testRomance) {
    vector<Movie> listOfRomanceMovies = imdbParser::scrapeGenres({"romance"});
    EXPECT_EQ(listOfRomanceMovies.at(0).name, "The Little Mermaid");
    EXPECT_EQ(listOfRomanceMovies.at(1).name, "Barbie");
    EXPECT_EQ(listOfRomanceMovies.at(2).name, "Asteroid City");
    EXPECT_EQ(listOfRomanceMovies.at(3).name, "Queen Charlotte: A Bridgerton Story");

    EXPECT_EQ(listOfRomanceMovies.at(0).releaseDates, "(2023)");
    EXPECT_EQ(listOfRomanceMovies.at(1).releaseDates, "(2023)");
    EXPECT_EQ(listOfRomanceMovies.at(2).releaseDates, "(2023)");
    EXPECT_EQ(listOfRomanceMovies.at(3).releaseDates, "(2023)");
}

TEST(imdbParserTest, testTwoGenres) {
    vector<Movie> listOfHorrorRomanceMovies = imdbParser::scrapeGenres({"romance", "horror"});
    // Checking if the romance movies parsed are correct
    EXPECT_EQ(listOfHorrorRomanceMovies.at(0).name, "The Little Mermaid");
    EXPECT_EQ(listOfHorrorRomanceMovies.at(1).name, "Barbie");
    EXPECT_EQ(listOfHorrorRomanceMovies.at(2).name, "Asteroid City");

    EXPECT_EQ(listOfHorrorRomanceMovies.at(0).releaseDates, "(2023)");
    EXPECT_EQ(listOfHorrorRomanceMovies.at(1).releaseDates, "(2023)");
    EXPECT_EQ(listOfHorrorRomanceMovies.at(2).releaseDates, "(2023)");

     // Checking if the horror movies parsed are correct
    EXPECT_EQ(listOfHorrorRomanceMovies.at(10).name, "Yellowjackets");
    EXPECT_EQ(listOfHorrorRomanceMovies.at(11).name, "From");
    EXPECT_EQ(listOfHorrorRomanceMovies.at(12).name, "The Boogeyman");

    EXPECT_EQ(listOfHorrorRomanceMovies.at(10).releaseDates, "(2021– )");
    EXPECT_EQ(listOfHorrorRomanceMovies.at(11).releaseDates, "(2022– )");
    EXPECT_EQ(listOfHorrorRomanceMovies.at(12).releaseDates, "(2023)");
}

TEST(imdbParserTest, testInvalidGenre) {
    testing::internal::CaptureStdout();
    vector<Movie> listOfBogusMovies = imdbParser::scrapeGenres({"bogusGenre"});
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Please enter a valid genre. (bogusGenre is not a valid genre)\n");
}

TEST(imdbParserTest, testTwoInvalidGenre) {
    testing::internal::CaptureStdout();
    vector<Movie> listOfBogusMovies = imdbParser::scrapeGenres({"bogusGenre", "bogusGenre2"});
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Please enter a valid genre. (bogusGenre is not a valid genre)\nPlease enter a valid genre. (bogusGenre2 is not a valid genre)\n");
}

TEST(imdbParserTest, testOneInvalidGenreOneValid) {
    testing::internal::CaptureStdout();
    vector<Movie> listOfHorrorBogusMovies = imdbParser::scrapeGenres({"bogusGenre", "horror"});
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Please enter a valid genre. (bogusGenre is not a valid genre)\n");

    EXPECT_EQ(listOfHorrorBogusMovies.at(0).name, "Yellowjackets");
    EXPECT_EQ(listOfHorrorBogusMovies.at(1).name, "From");
    EXPECT_EQ(listOfHorrorBogusMovies.at(2).name, "The Boogeyman");
    EXPECT_EQ(listOfHorrorBogusMovies.at(3).name, "The Walking Dead");

    EXPECT_EQ(listOfHorrorBogusMovies.at(0).releaseDates, "(2021– )");
    EXPECT_EQ(listOfHorrorBogusMovies.at(1).releaseDates, "(2022– )");
    EXPECT_EQ(listOfHorrorBogusMovies.at(2).releaseDates, "(2023)");
    EXPECT_EQ(listOfHorrorBogusMovies.at(3).releaseDates, "(2010–2022)");
}

#endif
