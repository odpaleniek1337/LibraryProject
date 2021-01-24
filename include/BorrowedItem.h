#ifndef LIBRARY_BORROWEDITEM_H
#define LIBRARY_BORROWEDITEM_H
#include <string>
using std::string;

class BorrowedItem {
private:
    string borrowTime;
    int ID;
    int maxDays;
    string title;
    int quantity;
public:
    string getCurrentTime();
    int getID();
    string getBorrowedTime();
    int getQuantity();
};
#endif //LIBRARY_BORROWEDITEM_H
