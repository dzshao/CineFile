#ifndef _IMDBPARSER_H_
using std::string;

class imdbParser {
    private:
        set<Director> findDirectorList(const string&);
        set<Actor> findActorList(const string&);
        set<Genre> findGenreList(const string&);
        unsigned findRating(const string&);
        string findTitle(const string&);
    public:
        vector<string>& scrapeGenres(const vector<Genre>&);
        string& scrapeMovie(const string&);
};

#endif