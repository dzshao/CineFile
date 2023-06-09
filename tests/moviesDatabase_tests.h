#ifndef MOVIES_DATABASE_TESTS
#define MOVIES_DATABASE_TESTS

#include <gtest/gtest.h>

#include "../header/database/moviesDatabase.h"

TEST(moviesDatabaseTests, addMovies) {
    Movie randomMovie{"Yellowjackets", "(2021– )", {{"Drama"}, {"Horror"}, {"Mystery"}}, 7.8, {{"N/A"}}, {{"Melanie Lynskey"}, {"Tawny Cypress"}, {"Sophie Nélisse"}, {"Jasmin Savoy Brown"}}};
    MoviesDatabase::addMovie(randomMovie);
    EXPECT_EQ(MoviesDatabase::getMovie("Yellowjackets").releaseDates, "(2021– )");
    EXPECT_DOUBLE_EQ(MoviesDatabase::getMovie("Yellowjackets").rating, 7.8);
    EXPECT_EQ(MoviesDatabase::getMovie("Yellowjackets").genreList.size(), 3);
    EXPECT_EQ(MoviesDatabase::getMovie("Yellowjackets").genreList.at(1).getName(), "Horror");
    EXPECT_EQ(MoviesDatabase::getMovie("Yellowjackets").directorList.at(0).getName(), "N/A");
}

TEST(moviesDatabaseTests, addEmptyMovie) {
    Movie randomMovie{};
    MoviesDatabase::addMovie(randomMovie);
    EXPECT_EQ(MoviesDatabase::getMovie("").releaseDates, "");
    EXPECT_DOUBLE_EQ(MoviesDatabase::getMovie("").rating, 0.0);
}

TEST(moviesDatabaseTests, addSecondMovie) {
    Movie randomMovie2{"From", "(2022– )", {{"Drama"}, {"Horror"}, {"Mystery"}}, 7.7, {{"N/A"}}, {{"Scott McCord"}, {"Harold Perrineau"}, {"Catalina Sandino Moreno"}, {"Eion Bailey"}}};
    MoviesDatabase::addMovie(randomMovie2);
    EXPECT_EQ(MoviesDatabase::getMovie("From").releaseDates, "(2022– )");
    EXPECT_DOUBLE_EQ(MoviesDatabase::getMovie("From").rating, 7.7);
    EXPECT_EQ(MoviesDatabase::getMovie("From").genreList.at(1).getName(), "Horror");
    EXPECT_EQ(MoviesDatabase::getMovie("From").castList.at(0).getName(), "Scott McCord");
    EXPECT_EQ(MoviesDatabase::getMovie("From").castList.at(2).getName(), "Catalina Sandino Moreno");
}

TEST(moviesDatabaseTests, addGenre) {
    Genre newGenre{"Romance"};
    MoviesDatabase::addGenre(newGenre);
    EXPECT_EQ(MoviesDatabase::getGenre("Romance").getName(), "Romance");
}

TEST(moviesDatabaseTests, addGenre2) {
    Genre newGenre{"Action"};
    newGenre.addMovie({"Five Nights at Freddy's"});
    MoviesDatabase::addGenre(newGenre);
    EXPECT_EQ(MoviesDatabase::getGenre("Action").getName(), "Action");
    EXPECT_EQ(MoviesDatabase::getGenre("Action").getMovieList()["Five Nights at Freddy's"].name, "Five Nights at Freddy's");
}

TEST(moviesDatabaseTests, addGenre3) {
    Genre newGenre{"Horror"};
    MoviesDatabase::addGenre(newGenre);
    EXPECT_EQ(MoviesDatabase::getGenre("Horror").getName(), "Horror");
    // Check if previously added Genres are still there
    EXPECT_EQ(MoviesDatabase::getGenre("Romance").getName(), "Romance");
    EXPECT_EQ(MoviesDatabase::getGenre("Action").getName(), "Action");
}

TEST(moviesDatabaseTests, addActor) {
    Actor newActor{"Freddy Kreuger"};
    MoviesDatabase::addActor(newActor);
    EXPECT_EQ(MoviesDatabase::getActor("Freddy Kreuger").getName(), "Freddy Kreuger");
}

TEST(moviesDatabaseTests, addActor2) {
    Actor newActor{"Minatozaki Sana"};
    newActor.addMovie("So-Fi Stadium Concert June 10th");
    MoviesDatabase::addActor(newActor);
    EXPECT_EQ(MoviesDatabase::getActor("Minatozaki Sana").getName(), "Minatozaki Sana");
    EXPECT_EQ(MoviesDatabase::getActor("Minatozaki Sana").getMovieList().at(0), "So-Fi Stadium Concert June 10th");
}

TEST(moviesDatabaseTests, addActor3) {
    Actor newActor{"Dwight Fairfield"};
    MoviesDatabase::addActor(newActor);
    EXPECT_EQ(MoviesDatabase::getActor("Dwight Fairfield").getName(), "Dwight Fairfield");
    // Check if previously added Actors are still there
    EXPECT_EQ(MoviesDatabase::getActor("Freddy Kreuger").getName(), "Freddy Kreuger");
    EXPECT_EQ(MoviesDatabase::getActor("Minatozaki Sana").getName(), "Minatozaki Sana");
}

TEST(moviesDatabaseTests, addDirector) {
    Director newDirector{"Goku"};
    MoviesDatabase::addDirector(newDirector);
    EXPECT_EQ(MoviesDatabase::getDirector("Goku").getName(), "Goku");
}

TEST(moviesDatabaseTests, addDirector2) {
    Director newDirector{"Im Nayeon"};
    newDirector.addMovie("Pop");
    MoviesDatabase::addDirector(newDirector);
    EXPECT_EQ(MoviesDatabase::getDirector("Im Nayeon").getName(), "Im Nayeon");
    EXPECT_EQ(MoviesDatabase::getDirector("Im Nayeon").getMovieList().at(0), "Pop");
}

TEST(moviesDatabaseTests, addDirector3) {
    Director newDirector{"Beerus"};
    MoviesDatabase::addDirector(newDirector);
    EXPECT_EQ(MoviesDatabase::getDirector("Beerus").getName(), "Beerus");
    // Check if previously added Directors are still there
    EXPECT_EQ(MoviesDatabase::getDirector("Goku").getName(), "Goku");
    EXPECT_EQ(MoviesDatabase::getDirector("Im Nayeon").getName(), "Im Nayeon");
}

TEST(moviesDatabaseTests, getMovieList1) {
    EXPECT_EQ(MoviesDatabase::getMovieList()["Yellowjackets"].releaseDates, "(2021– )");
    EXPECT_DOUBLE_EQ(MoviesDatabase::getMovieList()["Yellowjackets"].rating, 7.8);
    EXPECT_EQ(MoviesDatabase::getMovieList()["Yellowjackets"].genreList.size(), 3);
    EXPECT_EQ(MoviesDatabase::getMovieList()["Yellowjackets"].genreList.at(1).getName(), "Horror");
    EXPECT_EQ(MoviesDatabase::getMovieList()["Yellowjackets"].directorList.at(0).getName(), "N/A");
}

TEST(moviesDatabaseTests, getMovieList2) {
    EXPECT_EQ(MoviesDatabase::getMovieList()["From"].releaseDates, "(2022– )");
    EXPECT_DOUBLE_EQ(MoviesDatabase::getMovieList()["From"].rating, 7.7);
    EXPECT_EQ(MoviesDatabase::getMovieList()["From"].genreList.at(1).getName(), "Horror");
    EXPECT_EQ(MoviesDatabase::getMovieList()["From"].castList.at(0).getName(), "Scott McCord");
    EXPECT_EQ(MoviesDatabase::getMovieList()["From"].castList.at(2).getName(), "Catalina Sandino Moreno");
}


TEST(moviesDatabaseTests, getGenreList1) {
    EXPECT_EQ(MoviesDatabase::getGenreList()["Action"].getName(), "Action");
    EXPECT_EQ(MoviesDatabase::getGenreList()["Action"].getMovieList()["Five Nights at Freddy's"].name, "Five Nights at Freddy's");
}

TEST(moviesDatabaseTests, getGenreList2) {
    Genre newGenre{"Horror"};
    MoviesDatabase::addGenre(newGenre);
    EXPECT_EQ(MoviesDatabase::getGenreList()["Horror"].getName(), "Horror");
    // Check if previously added Genres are still there
    EXPECT_EQ(MoviesDatabase::getGenreList()["Romance"].getName(), "Romance");
    EXPECT_EQ(MoviesDatabase::getGenreList()["Action"].getName(), "Action");
}

TEST(moviesDatabaseTests, getActorList1) {
    EXPECT_EQ(MoviesDatabase::getActorList()["Freddy Kreuger"].getName(), "Freddy Kreuger");
}

TEST(moviesDatabaseTests, getActorList2) {
    EXPECT_EQ(MoviesDatabase::getActorList()["Minatozaki Sana"].getName(), "Minatozaki Sana");
    EXPECT_EQ(MoviesDatabase::getActorList()["Minatozaki Sana"].getMovieList().at(0), "So-Fi Stadium Concert June 10th");
}

TEST(moviesDatabaseTests, getDirectorList1) {
    EXPECT_EQ(MoviesDatabase::getDirectorList()["Im Nayeon"].getName(), "Im Nayeon");
    EXPECT_EQ(MoviesDatabase::getDirectorList()["Im Nayeon"].getMovieList().at(0), "Pop");
}

TEST(moviesDatabaseTests, getDirectorList2) {
    Director newDirector{"Beerus"};
    MoviesDatabase::addDirector(newDirector);
    EXPECT_EQ(MoviesDatabase::getDirectorList()["Beerus"].getName(), "Beerus");
    // Check if previously added Directors are still there
    EXPECT_EQ(MoviesDatabase::getDirectorList()["Goku"].getName(), "Goku");
    EXPECT_EQ(MoviesDatabase::getDirectorList()["Im Nayeon"].getName(), "Im Nayeon");
}
#endif