#ifndef IMDB_PARSER_TESTS
#define IMDB_PARSER_TESTS

#include <gtest/gtest.h>

#include "../header/webscraping/imdbParser.h"
#include "../header/database/genre.h"

// Current top movies of each genre
static const vector<Movie> imdbHorrorList = {{"Yellowjackets", "(2021– )", {{"Drama"}, {"Horror"}, {"Mystery"}}, "7.8", {{"N/A"}}},
                                             {"From", "(2022– )", {{"Drama"}, {"Horror"}, {"Mystery"}}, "7.7", {{"N/A"}}}, 
                                             {"The Boogeyman", "(2023)", {{"Horror"}, {"Mystery"}, {"Thriller"}}, "6.2", {{"Rob Savage"}}}, 
                                             {"The Walking Dead", "(2010–2022)", {{"Drama"}, {"Horror"}, {"Thriller"}}, "8.1", {{"N/A"}}}};

static const vector<Movie> imdbRomanceList {{"The Little Mermaid", "(2023)", {{"Adventure"}, {"Family"}, {"Fantasy"}}, "7.2", {{"Rob Marshall"}}},
                                            {"Barbie", "(2023)", {{"Adventure"}, {"Comedy"}, {"Fantasy"}}, "N/A", {{"Greta Gerwig"}}}, 
                                            {"Asteroid City", "(2023)", {{"Comedy"}, {"Drama"}, {"Romance"}}, "6.8", {{"Wes Anderson"}}}, 
                                            {"Queen Charlotte: A Bridgerton Story", "(2023)", {{"Drama"}, {"History"}, {"Romance"}}, "7.3", {{"N/A"}}}};

TEST(imdbParserTest, testHorror) {
    vector<Movie> listOfHorrorMovies = imdbParser::scrapeGenres({"horror"});

    // Check titles
    EXPECT_EQ(listOfHorrorMovies.at(0).name, imdbHorrorList.at(0).name);
    EXPECT_EQ(listOfHorrorMovies.at(1).name, imdbHorrorList.at(1).name);
    EXPECT_EQ(listOfHorrorMovies.at(2).name, imdbHorrorList.at(2).name);
    EXPECT_EQ(listOfHorrorMovies.at(3).name, imdbHorrorList.at(3).name);

    // Check release dates
    EXPECT_EQ(listOfHorrorMovies.at(0).releaseDates, imdbHorrorList.at(0).releaseDates);
    EXPECT_EQ(listOfHorrorMovies.at(1).releaseDates, imdbHorrorList.at(1).releaseDates);
    EXPECT_EQ(listOfHorrorMovies.at(2).releaseDates, imdbHorrorList.at(2).releaseDates);
    EXPECT_EQ(listOfHorrorMovies.at(3).releaseDates, imdbHorrorList.at(3).releaseDates);

    // Check genre names
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < imdbHorrorList.at(i).genreList.size(); ++j) {
            EXPECT_EQ(listOfHorrorMovies.at(i).genreList.at(j).getName(), imdbHorrorList.at(i).genreList.at(j).getName());
        }
    }

    // Check ratings
    EXPECT_EQ(listOfHorrorMovies.at(0).rating, imdbHorrorList.at(0).rating);
    EXPECT_EQ(listOfHorrorMovies.at(1).rating, imdbHorrorList.at(1).rating);
    EXPECT_EQ(listOfHorrorMovies.at(2).rating, imdbHorrorList.at(2).rating);
    EXPECT_EQ(listOfHorrorMovies.at(3).rating, imdbHorrorList.at(3).rating);

    // Check Director names
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < imdbHorrorList.at(i).directorList.size(); ++j) {
            EXPECT_EQ(listOfHorrorMovies.at(i).directorList.at(j).getName(), imdbHorrorList.at(i).directorList.at(j).getName());
        }
    }
}

TEST(imdbParserTest, testRomance) {
    vector<Movie> listOfRomanceMovies = imdbParser::scrapeGenres({"romance"});
    
    // Check titles
    EXPECT_EQ(listOfRomanceMovies.at(0).name, imdbRomanceList.at(0).name);
    EXPECT_EQ(listOfRomanceMovies.at(1).name, imdbRomanceList.at(1).name);
    EXPECT_EQ(listOfRomanceMovies.at(2).name, imdbRomanceList.at(2).name);
    EXPECT_EQ(listOfRomanceMovies.at(3).name, imdbRomanceList.at(3).name);

    // Check release dates
    EXPECT_EQ(listOfRomanceMovies.at(0).releaseDates, imdbRomanceList.at(0).releaseDates);
    EXPECT_EQ(listOfRomanceMovies.at(1).releaseDates, imdbRomanceList.at(1).releaseDates);
    EXPECT_EQ(listOfRomanceMovies.at(2).releaseDates, imdbRomanceList.at(2).releaseDates);
    EXPECT_EQ(listOfRomanceMovies.at(3).releaseDates, imdbRomanceList.at(3).releaseDates);

    // Check genre names
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < imdbRomanceList.at(i).genreList.size(); ++j) {
            EXPECT_EQ(listOfRomanceMovies.at(i).genreList.at(j).getName(), imdbRomanceList.at(i).genreList.at(j).getName());
        }
    }

    // Check ratings
    EXPECT_EQ(listOfRomanceMovies.at(0).rating, imdbRomanceList.at(0).rating);
    EXPECT_EQ(listOfRomanceMovies.at(1).rating, imdbRomanceList.at(1).rating);
    EXPECT_EQ(listOfRomanceMovies.at(2).rating, imdbRomanceList.at(2).rating);
    EXPECT_EQ(listOfRomanceMovies.at(3).rating, imdbRomanceList.at(3).rating);

    // Check Director names
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < imdbRomanceList.at(i).directorList.size(); ++j) {
            EXPECT_EQ(listOfRomanceMovies.at(i).directorList.at(j).getName(), imdbRomanceList.at(i).directorList.at(j).getName());
        }
    }
}

TEST(imdbParserTest, testTwoGenres) {
    vector<Movie> listOfHorrorRomanceMovies = imdbParser::scrapeGenres({"romance", "horror"});
    // Checking if the romance movies parsed are correct
    EXPECT_EQ(listOfHorrorRomanceMovies.at(0).name, imdbRomanceList.at(0).name);
    EXPECT_EQ(listOfHorrorRomanceMovies.at(1).name, imdbRomanceList.at(1).name);
    EXPECT_EQ(listOfHorrorRomanceMovies.at(2).name, imdbRomanceList.at(2).name);
    EXPECT_EQ(listOfHorrorRomanceMovies.at(3).name, imdbRomanceList.at(3).name);

     // Checking if the horror movies parsed are correct
    EXPECT_EQ(listOfHorrorRomanceMovies.at(10).name, imdbHorrorList.at(0).name);
    EXPECT_EQ(listOfHorrorRomanceMovies.at(11).name, imdbHorrorList.at(1).name);
    EXPECT_EQ(listOfHorrorRomanceMovies.at(12).name, imdbHorrorList.at(2).name);
    EXPECT_EQ(listOfHorrorRomanceMovies.at(13).name, imdbHorrorList.at(3).name);
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

    EXPECT_EQ(listOfHorrorBogusMovies.at(0).name, imdbHorrorList.at(0).name);
    EXPECT_EQ(listOfHorrorBogusMovies.at(1).name, imdbHorrorList.at(1).name);
    EXPECT_EQ(listOfHorrorBogusMovies.at(2).name, imdbHorrorList.at(2).name);
    EXPECT_EQ(listOfHorrorBogusMovies.at(3).name, imdbHorrorList.at(3).name);
}

#endif
