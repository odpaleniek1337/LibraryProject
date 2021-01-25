#ifndef LIBRARY_RENTER_H
#define LIBRARY_RENTER_H
#include <string>
using std::string;

class Renter {
private:
    int ID;
    string name;
    int maxItems;
    int currentItems;
public:
    Renter();
    Renter(int id, string name, int maxItems, int currentItems);

    int getCurrentItems();
};
#endif //LIBRARY_RENTER_H