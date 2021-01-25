#ifndef LIBRARY_MOVIE_H
#define LIBRARY_MOVIE_H
#include "Item.h"

class Movie : public Item {
private:
    string director;
public:
    Movie(int id, string title, string director, int quantity);
    string getDirector();
    ~Movie();
};
#endif //LIBRARY_MOVIE_H