#ifndef ACTOR_TESTS
#define ACTOR_TESTS

#include <gtest/gtest.h>
#include <vector>
#include "../header/database/actor.h"

using std::string;
using std::vector;

TEST(ActorTests, testConstructor1) {
    Actor testActor;
    string testName = testActor.getName();
    EXPECT_TRUE(testName.empty());
}

TEST(ActorTests, testConstructor2) {
    Actor testActor = Actor("Test Actor");
    string testName = testActor.getName();
    EXPECT_EQ(testName, "Test Actor");
}

TEST(ActorTests, testConstructor3andGetMovieList) {
    string testName = "Test Actor";
    vector<string> testMovieList = {"Hereditary", "Rushmore", "Barbie Movie"};
    Actor testActor = Actor(testName, testMovieList);
    EXPECT_EQ(testActor.getName(), testName);
    vector<string> getTestMovieList = testActor.getMovieList();
    EXPECT_EQ(testMovieList, getTestMovieList);
}

TEST(ActorTests, testSetName) {
    Actor testActor;
    testActor.setName("Test Actor");
    string testName = testActor.getName();
    EXPECT_EQ(testName, "Test Actor");
}

TEST(ActorTests, testAddMovie) {
    Actor testActor = Actor("Test Actor");
    Movie barbieMovie = {"Barbie", "(2023)", {{"Adventure"}, {"Comedy"}, {"Fantasy"}}, 0.0, {{"Greta Gerwig"}}, {{"Margot Robbie"}, {"Ryan Gosling"}, {"Dua Lipa"}, {"Ariana Greenblatt"}}};
    testActor.addMovie(barbieMovie);
    testActor.addMovie("Hereditary");
    vector<string> testMovieList = testActor.getMovieList();
    EXPECT_EQ(testMovieList.at(0), "Barbie");
    EXPECT_EQ(testMovieList.at(1), "Hereditary");
}

#endif