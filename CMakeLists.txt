cmake_minimum_required(VERSION 3.2)
project(movieRecommender)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

ADD_SUBDIRECTORY(googletest)

add_library(movie_recommend
    src/ScrapeWebsite.cpp
    src/imdbParser.cpp
    src/UserInterface.cpp
    src/database/moviesDatabase.cpp
    src/database/movie.cpp
    src/database/actor.cpp
    src/database/director.cpp
    src/database/genre.cpp
    src/database/person.cpp
)

ADD_EXECUTABLE(test
    tests/_unit_tests.cpp
)

ADD_EXECUTABLE(cinefile
    src/main.cpp
)

set_target_properties(movie_recommend PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

target_link_libraries(cinefile movie_recommend curl)
target_link_libraries(test gmock gtest movie_recommend curl)
