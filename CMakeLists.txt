cmake_minimum_required(VERSION 3.2)
project(movieRecommender)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

ADD_SUBDIRECTORY(googletest)

add_library(movie_recommend
    src/ScrapeWebsite.cpp
    src/imdbParser.cpp
)

ADD_EXECUTABLE(test
    tests/_unit_tests.cpp
)

target_link_libraries(test gmock)
target_link_libraries(test gtest)
target_link_libraries(test movie_recommend)
target_link_libraries(test curl)

target_link_options(test PRIVATE -lcurl)
