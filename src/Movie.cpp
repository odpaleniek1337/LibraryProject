#include "Movie.h"

Movie::Movie(int id, string title, string director, int quantity) : Item(id, title,10, quantity) {
    Movie::director = director;
}

string Movie::getDirector() {
    return Movie::director;
}

Movie::~Movie() {

}