#ifndef LIBRARY_MOVIE_H
#define LIBRARY_MOVIE_H
#include "Item.h"

class Movie : public Item {
private:
public:
    Movie(int id, std::string title, std::string director);
    virtual std::string toString() override;
    ~Movie();
};
#endif //LIBRARY_MOVIE_H