#ifndef MOVIESCORE_TESTS
#define MOVIESCORE_TESTS

#include <gtest/gtest.h>
#include "../header/database/MovieScore.h"

using std::string;

TEST(Moviescoretests, changescore ){
    movieScore tm = movieScore("Title");
    EXPECT_EQ(tm.getScore(), 1);

    tm.changeScore(2);
    EXPECT_EQ(tm.getScore(), 3);
}

#endif