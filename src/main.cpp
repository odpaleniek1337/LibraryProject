#include <iostream>
#include "time.h"
#include "RentingManager.h"
#include "Staff.h"
#include "Book.h"

int main() {
    /*time_t borrowedTime = time(NULL);
    struct tm * time = localtime(&borrowedTime);
    std::cout<<asctime(time)<<std::endl;*/
    RentingManager es;
    Book wojtek = Book(13,"Kordian", "Adam Małysz", 5);
    std::cout<<wojtek.getAuthor()<<std::endl;
    std::cout<<wojtek.getID()<<std::endl;
    std::cout<<wojtek.getQuantity()<<std::endl;
    std::cout<<wojtek.getTitle()<<std::endl;
    Staff maciek = Staff(1, "Maciek");
    std::cout<<maciek.getCurrentItems()<<std::endl;
    std::cout<<maciek.toString()<<std::endl;
    std::cout<<maciek.getName()<<std::endl;
    std::cout<<maciek.getID()<<std::endl;
    Rent rent1;
    std::shared_ptr<Book> ksiazkawojtka = std::make_shared<Book>(wojtek);
    std::shared_ptr<Staff>maciekptr = std::make_shared<Staff>(maciek);
    rent1.setRent(ksiazkawojtka,maciekptr);
    std::cout<<"gettime z wojtka: "<<rent1.getTime()<<std::endl;
    es.addRent(rent1);
    es.deleteRent(1);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
