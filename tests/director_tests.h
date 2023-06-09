#ifndef DIRECTOR_TESTS
#define DIRECTOR_TESTS

#include <gtest/gtest.h>
#include <vector>
#include "../header/database/actor.h"

using std::string;
using std::vector;

TEST(DirectorTests, testConstructor1) {
    Director testDirector;
    string testName = testDirector.getName();
    EXPECT_TRUE(testName.empty());
}

TEST(DirectorTests, testConstructor2) {
    Director testDirector = Director("Test Director");
    string testName = testDirector.getName();
    EXPECT_EQ(testName, "Test Director");
}

TEST(DirectorTests, testConstructor3andGetMovieList) {
    string testName = "Test Director";
    vector<string> testMovieList = {"Hereditary", "Rushmore", "Barbie Movie"};
    Director testDirector = Director(testName, testMovieList);
    EXPECT_EQ(testDirector.getName(), testName);
    vector<string> getTestMovieList = testDirector.getMovieList();
    EXPECT_EQ(testMovieList, getTestMovieList);
}

TEST(DirectorTests, testSetName) {
    Director testDirector;
    testDirector.setName("Test Director");
    string testName = testDirector.getName();
    EXPECT_EQ(testName, "Test Director");
}

TEST(DirectorTests, testAddMovie) {
    Director testDirector = Director("Test Director");
    Movie barbieMovie = {"Barbie", "(2023)", {{"Adventure"}, {"Comedy"}, {"Fantasy"}}, 0.0, {{"Greta Gerwig"}}, {{"Margot Robbie"}, {"Ryan Gosling"}, {"Dua Lipa"}, {"Ariana Greenblatt"}}};
    testDirector.addMovie(barbieMovie);
    testDirector.addMovie("Hereditary");
    vector<string> testMovieList = testDirector.getMovieList();
    EXPECT_EQ(testMovieList.at(0), "Barbie");
    EXPECT_EQ(testMovieList.at(1), "Hereditary");
}

#endif