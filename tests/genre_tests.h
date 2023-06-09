#ifndef GENRE_TESTS
#define GENRE_TESTS

#include <gtest/gtest.h>
#include <vector>
#include <unordered_map>
#include "../header/database/genre.h"
#include "../header/database/movie.h"

using std::vector;
using std::string;
using std::unordered_map;

Genre testHorror = Genre("Horror");
Genre testDrama = Genre("Drama");
Genre testThriller = Genre("Thriller");
vector<Genre> testGenreList = {{"Horror"}, {"Drama"}, {"Thriller"}};

Movie theLittleMermaidMovie = {"The Little Mermaid", "(2023)", {{"Adventure"}, {"Family"}, {"Fantasy"}}, 7.2, {{"Rob Marshall"}}, {{"Halle Bailey"}, {"Jonah Hauer-King"}, {"Melissa McCarthy"}, {"Javier Bardem"}}};
Movie barbieMovie = {"Barbie", "(2023)", {{"Adventure"}, {"Comedy"}, {"Fantasy"}}, 0.0, {{"Greta Gerwig"}}, {{"Margot Robbie"}, {"Ryan Gosling"}, {"Dua Lipa"}, {"Ariana Greenblatt"}}};
Movie asteroidCityMovie = {"Asteroid City", "(2023)", {{"Comedy"}, {"Drama"}, {"Romance"}}, 6.8, {{"Wes Anderson"}}, {{"Jason Schwartzman"}, {"Scarlett Johansson"}, {"Tom Hanks"}, {"Jeffrey Wright"}}};
Movie queenCharlotteMoive = {"Queen Charlotte: A Bridgerton Story", "(2023)", {{"Drama"}, {"History"}, {"Romance"}}, 7.3, {{"N/A"}}, {{"India Amarteifio"}, {"Adjoa Andoh"}, {"Michelle Fairley"}, {"Ruth Gemmell"}}};

TEST(GenreTests, testConstructor) {
    Genre testGenre;
    string testName = testGenre.getName();
    EXPECT_TRUE(testName.empty());
    unordered_map<string, Movie> testMovieMap = testGenre.getMovieList();
    EXPECT_TRUE(testMovieMap.empty());
}

TEST(GenreTests, testConstructor2) {
    Genre testHorror = Genre("Horror");
    EXPECT_EQ(testHorror.getName(), "Horror");
}

TEST(GenreTests, testConstructor3) {
    unordered_map<string, Movie> testMovieMap;
    testMovieMap["The Little Mermaid"] = theLittleMermaidMovie;
    testMovieMap["Barbie"] = barbieMovie;
    testMovieMap["Asteroid City"] = asteroidCityMovie;
    testMovieMap["Queen Charlotte: A Bridgerton Story"] = queenCharlotteMoive;

    Genre testGenre = Genre("Test", testMovieMap);

    EXPECT_EQ(testGenre.getName(), "Test");
    auto testSearch = testMovieMap.find("Barbie");
    EXPECT_TRUE(testSearch->first == "Barbie");
}

TEST(GenreTests, testSetName) {
    Genre testHorror = Genre("Drama");
    testHorror.setName("Horror");
    EXPECT_EQ(testHorror.getName(), "Horror");
}

TEST(GenreTests, testAddMovie) {
    Genre testGenre = Genre("Test");
    testGenre.addMovie(theLittleMermaidMovie);
    testGenre.addMovie(barbieMovie);
    testGenre.addMovie(asteroidCityMovie);
    testGenre.addMovie(queenCharlotteMoive);

    unordered_map<string, Movie> testMovieMap = testGenre.getMovieList();

    auto testSearch1 = testMovieMap.find("The Little Mermaid");
    EXPECT_TRUE(testSearch1->first == "The Little Mermaid");

    auto testSearch2 = testMovieMap.find("Barbie");
    EXPECT_TRUE(testSearch2->first == "Barbie");

    auto testSearch3 = testMovieMap.find("Asteroid City");
    EXPECT_TRUE(testSearch3->first == "Asteroid City");

    auto testSearch4 = testMovieMap.find("Queen Charlotte: A Bridgerton Story");
    EXPECT_TRUE(testSearch4->first == "Queen Charlotte: A Bridgerton Story");
}

#endif