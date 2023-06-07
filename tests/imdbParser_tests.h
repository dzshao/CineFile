#ifndef IMDB_PARSER_TESTS
#define IMDB_PARSER_TESTS

#include <gtest/gtest.h>

#include "../header/webscraping/imdbParser.h"

std::vector<Movie> horrorList{{"Yellowjackets", "(2021- )"}, 
                                       {"From", "(2022- )"}, 
                                       {"The Boogeyman", "(2023)"}, 
                                       {"The Walking Dead", "(2010-2022)"}};

std::vector<Movie> romanceList{{"The Little Mermaid", "(2023)", 7.2}, 
                                        {"Barbie", "(2023)"}, 
                                        {"Asteroid City", "(2023)"}, 
                                        {"Queen Charlotte: A Brigerton Story", "(2023)"}};

TEST(imdbParserTest, testHorror) {
    vector<Movie> listOfHorrorMovies = imdbParser::scrapeGenres({"horror"});
    EXPECT_EQ(listOfHorrorMovies.at(0).name, horrorList.at(0).name);
    EXPECT_EQ(listOfHorrorMovies.at(1).name, horrorList.at(1).name);
    EXPECT_EQ(listOfHorrorMovies.at(2).name, horrorList.at(2).name);
    EXPECT_EQ(listOfHorrorMovies.at(3).name, horrorList.at(3).name);

    EXPECT_EQ(listOfHorrorMovies.at(0).releaseDates, horrorList.at(0).releaseDates);
    EXPECT_EQ(listOfHorrorMovies.at(1).releaseDates, horrorList.at(1).releaseDates);
    EXPECT_EQ(listOfHorrorMovies.at(2).releaseDates, horrorList.at(2).releaseDates);
    EXPECT_EQ(listOfHorrorMovies.at(3).releaseDates, horrorList.at(3).releaseDates);
}

TEST(imdbParserTest, testRomance) {
    vector<Movie> listOfRomanceMovies = imdbParser::scrapeGenres({"romance"});
    EXPECT_EQ(listOfRomanceMovies.at(0).name, romanceList.at(0).name);
    EXPECT_EQ(listOfRomanceMovies.at(1).name, romanceList.at(1).name);
    EXPECT_EQ(listOfRomanceMovies.at(2).name, romanceList.at(2).name);
    EXPECT_EQ(listOfRomanceMovies.at(3).name, romanceList.at(3).name);

    EXPECT_EQ(listOfRomanceMovies.at(0).releaseDates, romanceList.at(0).releaseDates);
    EXPECT_EQ(listOfRomanceMovies.at(1).releaseDates, romanceList.at(1).releaseDates);
    EXPECT_EQ(listOfRomanceMovies.at(2).releaseDates, romanceList.at(2).releaseDates);
    EXPECT_EQ(listOfRomanceMovies.at(3).releaseDates, romanceList.at(3).releaseDates);
}

TEST(imdbParserTest, testTwoGenres) {
    vector<Movie> listOfHorrorRomanceMovies = imdbParser::scrapeGenres({"romance", "horror"});
    // Checking if the romance movies parsed are correct
    EXPECT_EQ(listOfHorrorRomanceMovies.at(0).name, romanceList.at(0).name);
    EXPECT_EQ(listOfHorrorRomanceMovies.at(1).name, romanceList.at(1).name);
    EXPECT_EQ(listOfHorrorRomanceMovies.at(2).name, romanceList.at(2).name);

    EXPECT_EQ(listOfHorrorRomanceMovies.at(0).releaseDates, romanceList.at(0).releaseDates);
    EXPECT_EQ(listOfHorrorRomanceMovies.at(1).releaseDates, romanceList.at(1).releaseDates);
    EXPECT_EQ(listOfHorrorRomanceMovies.at(2).releaseDates, romanceList.at(2).releaseDates);

     // Checking if the horror movies parsed are correct
    EXPECT_EQ(listOfHorrorRomanceMovies.at(10).name, horrorList.at(0).name);
    EXPECT_EQ(listOfHorrorRomanceMovies.at(11).name, horrorList.at(1).name);
    EXPECT_EQ(listOfHorrorRomanceMovies.at(12).name, horrorList.at(2).name);

    EXPECT_EQ(listOfHorrorRomanceMovies.at(10).releaseDates, horrorList.at(0).releaseDates);
    EXPECT_EQ(listOfHorrorRomanceMovies.at(11).releaseDates, horrorList.at(1).releaseDates);
    EXPECT_EQ(listOfHorrorRomanceMovies.at(12).releaseDates, horrorList.at(2).releaseDates);
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

    EXPECT_EQ(listOfHorrorBogusMovies.at(0).name, horrorList.at(0).name);
    EXPECT_EQ(listOfHorrorBogusMovies.at(1).name, horrorList.at(1).name);
    EXPECT_EQ(listOfHorrorBogusMovies.at(2).name, horrorList.at(2).name);
    EXPECT_EQ(listOfHorrorBogusMovies.at(3).name, horrorList.at(3).name);

    EXPECT_EQ(listOfHorrorBogusMovies.at(0).releaseDates, horrorList.at(0).releaseDates);
    EXPECT_EQ(listOfHorrorBogusMovies.at(1).releaseDates, horrorList.at(1).releaseDates);
    EXPECT_EQ(listOfHorrorBogusMovies.at(2).releaseDates, horrorList.at(2).releaseDates);
    EXPECT_EQ(listOfHorrorBogusMovies.at(3).releaseDates, horrorList.at(3).releaseDates);
}

#endif
