#include <gtest/gtest.h>

#include "./ScrapeWebsites_test.h"
#include "./imdbParser_tests.h"

int main(int ac, char* av[]) {
    ::testing::InitGoogleTest(&ac, av);
    return RUN_ALL_TESTS();
}