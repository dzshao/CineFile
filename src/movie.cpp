#include "../header/database/movie.h"

using std::endl;

std::ostream& operator<<(std::ostream& out, const Movie& outputMovie) {        
    out << outputMovie.name << endl
        << outputMovie.releaseDates << endl;
    for(unsigned i = 0; i < outputMovie.genreList.size() - 1; ++i) {
        out << outputMovie.genreList.at(i).getName() << ", ";
    }
    out << outputMovie.genreList.at(outputMovie.genreList.size() - 1).getName() << endl;

    out << outputMovie.rating << endl;

    for(unsigned i = 0; i < outputMovie.directorList.size() - 1; ++i) {
        out << outputMovie.directorList.at(i).getName() << ", ";
    }
    out << outputMovie.directorList.at(outputMovie.directorList.size() - 1).getName() << endl;   

    for(unsigned i = 0; i < outputMovie.castList.size() - 1; ++i) {
        out << outputMovie.castList.at(i).getName() << ", ";
    }
    out << outputMovie.castList.at(outputMovie.castList.size() - 1).getName();
    
    return out;
}