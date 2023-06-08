#ifndef IMDB_PARSER_TESTS
#define IMDB_PARSER_TESTS

#include <gtest/gtest.h>
#include <fstream>
#include "../header/webscraping/imdbParser.h"
#include "../header/database/genre.h"

// Current top movies of each genre
static const vector<Movie> imdbHorrorList = {{"Yellowjackets", "(2021– )", {{"Drama"}, {"Horror"}, {"Mystery"}}, 7.8, {{"N/A"}}, {{"Melanie Lynskey"}, {"Tawny Cypress"}, {"Sophie Nélisse"}, {"Jasmin Savoy Brown"}}},
                                             {"From", "(2022– )", {{"Drama"}, {"Horror"}, {"Mystery"}}, 7.7, {{"N/A"}}, {{"Scott McCord"}, {"Harold Perrineau"}, {"Catalina Sandino Moreno"}, {"Eion Bailey"}}}, 
                                             {"The Boogeyman", "(2023)", {{"Horror"}, {"Mystery"}, {"Thriller"}}, 6.2, {{"Rob Savage"}}, {{"Sophie Thatcher"}, {"Chris Messina"}, {"Vivien Lyra Blair"}, {"David Dastmalchian"}}}, 
                                             {"The Walking Dead", "(2010–2022)", {{"Drama"}, {"Horror"}, {"Thriller"}}, 8.1, {{"N/A"}}, {{"Andrew Lincoln"}, {"Norman Reedus"}, {"Melissa McBride"}, {"Lauren Cohan"}}}};

static const vector<Movie> imdbRomanceList = {{"The Little Mermaid", "(2023)", {{"Adventure"}, {"Family"}, {"Fantasy"}}, 7.2, {{"Rob Marshall"}}, {{"Halle Bailey"}, {"Jonah Hauer-King"}, {"Melissa McCarthy"}, {"Javier Bardem"}}},
                                              {"Barbie", "(2023)", {{"Adventure"}, {"Comedy"}, {"Fantasy"}}, 0.0, {{"Greta Gerwig"}}, {{"Margot Robbie"}, {"Ryan Gosling"}, {"Dua Lipa"}, {"Ariana Greenblatt"}}}, 
                                              {"Asteroid City", "(2023)", {{"Comedy"}, {"Drama"}, {"Romance"}}, 6.8, {{"Wes Anderson"}}, {{"Jason Schwartzman"}, {"Scarlett Johansson"}, {"Tom Hanks"}, {"Jeffrey Wright"}}}, 
                                              {"Queen Charlotte: A Bridgerton Story", "(2023)", {{"Drama"}, {"History"}, {"Romance"}}, 7.3, {{"N/A"}}, {{"India Amarteifio"}, {"Adjoa Andoh"}, {"Michelle Fairley"}, {"Ruth Gemmell"}}}};

static const vector<Movie> imdbActionList = {{"Spider-Man: Across the Spider-Verse", "(2023)", {{"Animation"}, {"Action"}, {"Adventure"}}, 9.1, {{"Joaquim Dos Santos"}, {"Kemp Powers"}, {"Justin K. Thompson"}}, {{"Shameik Moore"}, {"Hailee Steinfeld"}, {"Brian Tyree Henry"}, {"Luna Lauren Velez"}}},
                                             {"FUBAR", "(2023– )", {{"Action"}, {"Adventure"}, {"Thriller"}}, 6.5, {{"N/A"}}, {{"Arnold Schwarzenegger"}, {"Monica Barbaro"}, {"Milan Carter"}, {"Gabriel Luna"}}}, 
                                             {"Barry", "(2018–2023)", {{"Action"}, {"Comedy"}, {"Crime"}}, 8.4, {{"N/A"}}, {{"Bill Hader"}, {"Stephen Root"}, {"Sarah Goldberg"}, {"Anthony Carrigan"}}}, 
                                             {"John Wick: Chapter 4", "(2023)", {{"Action"}, {"Crime"}, {"Thriller"}}, 8.0, {{"Chad Stahelski"}}, {{"Keanu Reeves"}, {"Laurence Fishburne"},{"George Georgiou"}, {"Lance Reddick"}}}};


TEST(imdbParserTest, testScrapingHorror) {
    std::ifstream fileIn;
    fileIn.open("./tests/imdbHTML/horror.txt");
    ASSERT_TRUE(fileIn.is_open() && "Failed opening horror.txt");
    std::string fileReader;
    std::stringstream parse;
    while(getline(fileIn, fileReader)) {
        parse << fileReader << "\n"; 
    }
    fileIn.close();
    vector<Movie> listOfHorrorMovies;
    imdbParser::scrapeMovies(parse, listOfHorrorMovies, 10);

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
    EXPECT_DOUBLE_EQ(listOfHorrorMovies.at(0).rating, imdbHorrorList.at(0).rating);
    EXPECT_DOUBLE_EQ(listOfHorrorMovies.at(1).rating, imdbHorrorList.at(1).rating);
    EXPECT_DOUBLE_EQ(listOfHorrorMovies.at(2).rating, imdbHorrorList.at(2).rating);
    EXPECT_DOUBLE_EQ(listOfHorrorMovies.at(3).rating, imdbHorrorList.at(3).rating);

    // Check Director names
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < imdbHorrorList.at(i).directorList.size(); ++j) {
            EXPECT_EQ(listOfHorrorMovies.at(i).directorList.at(j).getName(), imdbHorrorList.at(i).directorList.at(j).getName());
        }
    }

    // Check Director names
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < imdbHorrorList.at(i).castList.size(); ++j) {
            EXPECT_EQ(listOfHorrorMovies.at(i).castList.at(j).getName(), imdbHorrorList.at(i).castList.at(j).getName());
        }
    }
}

TEST(imdbParserTest, testScrapingRomance) {
    std::ifstream fileIn;
    fileIn.open("./tests/imdbHTML/romance.txt");
    ASSERT_TRUE(fileIn.is_open() && "Failed opening romance.txt");
    std::string fileReader;
    std::stringstream parse;
    while(getline(fileIn, fileReader)) {
        parse << fileReader << "\n"; 
    }
    fileIn.close();
    vector<Movie> listOfRomanceMovies;
    imdbParser::scrapeMovies(parse, listOfRomanceMovies, 10);
    
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
    EXPECT_DOUBLE_EQ(listOfRomanceMovies.at(0).rating, imdbRomanceList.at(0).rating);
    EXPECT_DOUBLE_EQ(listOfRomanceMovies.at(1).rating, imdbRomanceList.at(1).rating);
    EXPECT_DOUBLE_EQ(listOfRomanceMovies.at(2).rating, imdbRomanceList.at(2).rating);
    EXPECT_DOUBLE_EQ(listOfRomanceMovies.at(3).rating, imdbRomanceList.at(3).rating);

    // Check Director names
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < imdbRomanceList.at(i).directorList.size(); ++j) {
            EXPECT_EQ(listOfRomanceMovies.at(i).directorList.at(j).getName(), imdbRomanceList.at(i).directorList.at(j).getName());
        }
    }

    // Check Cast names
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < imdbRomanceList.at(i).castList.size(); ++j) {
            EXPECT_EQ(listOfRomanceMovies.at(i).castList.at(j).getName(), imdbRomanceList.at(i).castList.at(j).getName());
        }
    }
}

TEST(imdbParserTest, testScrapingAction) {
    std::ifstream fileIn;
    fileIn.open("./tests/imdbHTML/action.txt");
    ASSERT_TRUE(fileIn.is_open() && "Failed opening action.txt");
    std::string fileReader;
    std::stringstream parse;
    while(getline(fileIn, fileReader)) {
        parse << fileReader << "\n"; 
    }
    fileIn.close();
    vector<Movie> listOfActionMovies;
    imdbParser::scrapeMovies(parse, listOfActionMovies, 10);
    
    // Check titles
    EXPECT_EQ(listOfActionMovies.at(0).name, imdbActionList.at(0).name);
    EXPECT_EQ(listOfActionMovies.at(1).name, imdbActionList.at(1).name);
    EXPECT_EQ(listOfActionMovies.at(2).name, imdbActionList.at(2).name);
    EXPECT_EQ(listOfActionMovies.at(3).name, imdbActionList.at(3).name);

    // Check release dates
    EXPECT_EQ(listOfActionMovies.at(0).releaseDates, imdbActionList.at(0).releaseDates);
    EXPECT_EQ(listOfActionMovies.at(1).releaseDates, imdbActionList.at(1).releaseDates);
    EXPECT_EQ(listOfActionMovies.at(2).releaseDates, imdbActionList.at(2).releaseDates);
    EXPECT_EQ(listOfActionMovies.at(3).releaseDates, imdbActionList.at(3).releaseDates);

    // Check genre names
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < imdbActionList.at(i).genreList.size(); ++j) {
            EXPECT_EQ(listOfActionMovies.at(i).genreList.at(j).getName(), imdbActionList.at(i).genreList.at(j).getName());
        }
    }

    // Check ratings
    EXPECT_DOUBLE_EQ(listOfActionMovies.at(0).rating, imdbActionList.at(0).rating);
    EXPECT_DOUBLE_EQ(listOfActionMovies.at(1).rating, imdbActionList.at(1).rating);
    EXPECT_DOUBLE_EQ(listOfActionMovies.at(2).rating, imdbActionList.at(2).rating);
    EXPECT_DOUBLE_EQ(listOfActionMovies.at(3).rating, imdbActionList.at(3).rating);

    // Check Director names
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < imdbActionList.at(i).directorList.size(); ++j) {
            EXPECT_EQ(listOfActionMovies.at(i).directorList.at(j).getName(), imdbActionList.at(i).directorList.at(j).getName());
        }
    }

    // Check Director names
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < imdbActionList.at(i).castList.size(); ++j) {
            EXPECT_EQ(listOfActionMovies.at(i).castList.at(j).getName(), imdbActionList.at(i).castList.at(j).getName());
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
