#include "../../header/database/genre.h"
#include "../../header/database/movie.h"

using std::endl;

std::ostream& operator<<(std::ostream& out, const Movie& outputMovie) {
    out << outputMovie.name << " " << outputMovie.releaseDates << ":" << endl;

    out << "Rating: ";
    if (outputMovie.rating == 0.0) {
        out << "N/A" << endl;
    } 
    else {
        out << outputMovie.rating << "/10" << endl;
    }

    out << "Genre(s): ";
    for(unsigned i = 0; i < outputMovie.genreList.size() - 1; ++i) {
        out << outputMovie.genreList.at(i).getName() << ", ";
    }
    out << outputMovie.genreList.at(outputMovie.genreList.size() - 1).getName() << endl;

    out << "Directed by: ";
    for(unsigned i = 0; i < outputMovie.directorList.size() - 1; ++i) {
        out << outputMovie.directorList.at(i).getName() << ", ";
    }
    out << outputMovie.directorList.at(outputMovie.directorList.size() - 1).getName() << endl;   


    out << "Starring: ";
    for(unsigned i = 0; i < outputMovie.castList.size() - 1; ++i) {
        out << outputMovie.castList.at(i).getName() << ", ";
    }
    out << outputMovie.castList.at(outputMovie.castList.size() - 1).getName();
    
    return out;
}