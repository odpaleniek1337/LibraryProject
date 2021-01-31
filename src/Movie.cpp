#include "Movie.h"

Movie::Movie(int id, std::string title, std::string director, int quantity) : Item(id, title, director, 10, quantity) {
}

Movie::~Movie() {

}