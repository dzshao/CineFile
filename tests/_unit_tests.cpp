#include <gtest/gtest.h>

#include "./moviesDatabase_tests.h"
#include "./ScrapeWebsites_test.h"
#include "./imdbParser_tests.h"
#include "./genre_tests.h"
#include "./movie_tests.h"
#include "./person_tests.h"
#include "./actor_tests.h"
#include "./director_tests.h"

int main(int ac, char* av[]) {
    ::testing::InitGoogleTest(&ac, av);
    return RUN_ALL_TESTS();
}