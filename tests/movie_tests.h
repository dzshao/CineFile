#ifndef MOVIE_TESTS
#define MOVIE_TESTS

#include <gtest/gtest.h>
#include <sstream>
#include "../header/database/movie.h"

using std::string;

TEST(MovieTests, testConstruction) {
        Movie barbieMovie = {"Barbie", "(2023)", {{"Adventure"}, {"Comedy"}, {"Fantasy"}}, 0.0, {{"Greta Gerwig"}}, {{"Margot Robbie"}, {"Ryan Gosling"}, {"Dua Lipa"}, {"Ariana Greenblatt"}}};

        EXPECT_EQ(barbieMovie.name, "Barbie");
        EXPECT_EQ(barbieMovie.releaseDates, "(2023)");
        EXPECT_EQ(barbieMovie.genreList.at(0).getName(), "Adventure");
        EXPECT_EQ(barbieMovie.genreList.at(1).getName(), "Comedy");
        EXPECT_EQ(barbieMovie.genreList.at(2).getName(), "Fantasy");
        EXPECT_EQ(barbieMovie.rating, 0.0);
        EXPECT_EQ(barbieMovie.directorList.at(0).getName(), "Greta Gerwig");
        EXPECT_EQ(barbieMovie.castList.at(0).getName(), "Margot Robbie");
        EXPECT_EQ(barbieMovie.castList.at(1).getName(), "Ryan Gosling");
        EXPECT_EQ(barbieMovie.castList.at(2).getName(), "Dua Lipa");
        EXPECT_EQ(barbieMovie.castList.at(3).getName(), "Ariana Greenblatt");
}

TEST(MovieTests, testOstreamOverload) {
    Movie theLittleMermaidMovie = {"The Little Mermaid", "(2023)", {{"Adventure"}, {"Family"}, {"Fantasy"}}, 7.2, {{"Rob Marshall"}}, {{"Halle Bailey"}, {"Jonah Hauer-King"}, {"Melissa McCarthy"}, {"Javier Bardem"}}};
    string testOutput = "The Little Mermaid (2023):\nRating: 7.2/10\nGenre(s): Adventure, Family, Fantasy\nDirected by: Rob Marshall\nStarring: Halle Bailey, Jonah Hauer-King, Melissa McCarthy, Javier Bardem";
    
    EXPECT_EQ(testOutput, ::testing::PrintToString(theLittleMermaidMovie));
}
#endif