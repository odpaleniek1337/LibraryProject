#ifndef LIBRARY_MOVIE_H
#define LIBRARY_MOVIE_H
#include "Item.h"

class Movie : public Item {
private:
public:
    Movie(int id, std::string title, std::string director, int quantity);
    ~Movie();
};
#endif //LIBRARY_MOVIE_H