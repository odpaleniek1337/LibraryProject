#ifndef LIBRARY_MOVIE_H
#define LIBRARY_MOVIE_H
#include "BorrowedItem.h"

class Movie : public BorrowedItem {
private:
    string director;
public:
    Movie(int ID, string title, string director, int quantity);
    ~Movie();
};
#endif //LIBRARY_MOVIE_H