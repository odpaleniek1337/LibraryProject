#ifndef LIBRARY_RENTINGMANAGER_H
#define LIBRARY_RENTINGMANAGER_H
#include <vector>
#include <memory>
#include <string>
#include "Rent.h" //moze to usunac

using std::string;
using std::vector;

class Rent;
typedef std::shared_ptr<Rent> bItem;

class RentingManager {
private:
    vector<bItem> rentedItems;
    double idRent;
public:
    RentingManager();
    ~RentingManager();
    void addRent(Rent newRent);
    void deleteRent(int id);
    bItem getRent(int id);
    double getSize();
    double getIDRent();
};
#endif //LIBRARY_RENTINGMANAGER_H