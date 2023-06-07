#ifndef IMDB_PARSER_TESTS
#define IMDB_PARSER_TESTS

#include <gtest/gtest.h>

#include "../header/webscraping/imdbParser.h"
#include "../header/database/genre.h"

// Current top movies of each genre
static const vector<Movie> imdbHorrorList = {{"Yellowjackets", "(2021– )", {{"Drama"}, {"Horror"}, {"Mystery"}}, "7.8"},
                                             {"From", "(2022– )", {{"Drama"}, {"Horror"}, {"Mystery"}}, "7.7"}, 
                                             {"The Boogeyman", "(2023)", {{"Horror"}, {"Mystery"}, {"Thriller"}}, "6.2"}, 
                                             {"The Walking Dead", "(2010–2022)", {{"Drama"}, {"Horror"}, {"Thriller"}}, "8.1"}};

static const vector<Movie> imdbRomanceList {{"The Little Mermaid", "(2023)", {{"Adventure"}, {"Family"}, {"Fantasy"}}, "7.2"},
                                            {"Barbie", "(2023)", {{"Adventure"}, {"Comedy"}, {"Fantasy"}}, "N/A"}, 
                                            {"Asteroid City", "(2023)", {{"Comedy"}, {"Drama"}, {"Romance"}}, "6.8"}, 
                                            {"Queen Charlotte: A Bridgerton Story", "(2023)", {{"Drama"}, {"History"}, {"Romance"}}, "7.3"}};

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
    for (int i = 0; i < imdbHorrorList.at(0).genreList.size(); ++i) {
        EXPECT_EQ(listOfHorrorMovies.at(0).genreList.at(i).getName(), imdbHorrorList.at(0).genreList.at(i).getName());
    }

    for (int i = 0; i < imdbHorrorList.at(1).genreList.size(); ++i) {
        EXPECT_EQ(listOfHorrorMovies.at(1).genreList.at(i).getName(), imdbHorrorList.at(1).genreList.at(i).getName());
    }

    // Check ratings
    EXPECT_EQ(listOfHorrorMovies.at(0).rating, imdbHorrorList.at(0).rating);
    EXPECT_EQ(listOfHorrorMovies.at(1).rating, imdbHorrorList.at(1).rating);
    EXPECT_EQ(listOfHorrorMovies.at(2).rating, imdbHorrorList.at(2).rating);
    EXPECT_EQ(listOfHorrorMovies.at(3).rating, imdbHorrorList.at(3).rating);
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
    for (int i = 0; i < imdbRomanceList.at(0).genreList.size(); ++i) {
        EXPECT_EQ(listOfRomanceMovies.at(0).genreList.at(i).getName(), imdbRomanceList.at(0).genreList.at(i).getName());
    }

    for (int i = 0; i < imdbHorrorList.at(1).genreList.size(); ++i) {
        EXPECT_EQ(listOfRomanceMovies.at(1).genreList.at(i).getName(), imdbRomanceList.at(1).genreList.at(i).getName());
    }

    // Check ratings
    EXPECT_EQ(listOfRomanceMovies.at(0).rating, imdbRomanceList.at(0).rating);
    EXPECT_EQ(listOfRomanceMovies.at(1).rating, imdbRomanceList.at(1).rating);
    EXPECT_EQ(listOfRomanceMovies.at(2).rating, imdbRomanceList.at(2).rating);
    EXPECT_EQ(listOfRomanceMovies.at(3).rating, imdbRomanceList.at(3).rating);
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
