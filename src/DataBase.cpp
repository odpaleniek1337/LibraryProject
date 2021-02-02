#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "DataBase.h"
#include "Book.h"
#include "Movie.h"
#include "Other.h"
#include "Staff.h"
#include "Student.h"

DataBase::DataBase() {

}

DataBase::~DataBase() {

}

void DataBase::readFile(RentingManager &manager) {
    std::fstream finItem, finRenter, finRents;
    int check1 = 0;
    int check2 = 0;
    int check3 = 0;
    try {
        finItem.open("../items.csv", std::ios::in);
        if( !finItem ) throw std::ios::failure( "Error in opening file!" );
        std::vector<string> rowI;
        string lineI, wordI, tempI;
        while (finItem.good()) {
            rowI.clear();
            std::getline(finItem, lineI);
            std::stringstream sI(lineI);
            while (getline(sI, wordI, ',')) {
                rowI.push_back(wordI);
            }
            if (rowI.size() == 4) {//check czy ma odpowiednia ilosc wartosci w linii
                if (rowI[0] == "Book") {
                    Book newBook = Book(stoi(rowI[1]), rowI[2], rowI[3]);
                    std::shared_ptr<Book> bookptr = std::make_shared<Book>(newBook);
                    DataBase::addItem(bookptr);
                } else if (rowI[0] == "Movie") {
                    Movie newMovie = Movie(stoi(rowI[1]), rowI[2], rowI[3]);
                    std::shared_ptr<Movie> movieptr = std::make_shared<Movie>(newMovie);
                    DataBase::addItem(movieptr);
                }
            }
            else {
                check1++;
            }
        }
    }
    catch(std::exception const& e)
    {
        check1++;
        std::cerr << e.what() <<" for items.csv file"<<std::endl;
    }
    finItem.close();

    try {
        finRenter.open("../renters.csv", std::ios::in);
        if( !finRenter ) throw std::ios::failure( "Error opening file!" ) ;
        std::vector<string> rowR;
        string lineR, wordR, tempR;
        while (finRenter.good()) {
            rowR.clear();
            std::getline(finRenter, lineR);
            std::stringstream sR(lineR);
            while (getline(sR, wordR, ',')) {
                rowR.push_back(wordR);
            }
            if (rowR.size() == 3) {//check czy ma odpowiednia ilosc wartosci w linii
                if (rowR[0] == "Other") {
                    Other newOther = Other(stoi(rowR[1]), rowR[2]);
                    std::shared_ptr<Other> otherptr = std::make_shared<Other>(newOther);
                    DataBase::addRenter(otherptr);
                } else if (rowR[0] == "Staff") {
                    Staff newStaff = Staff(stoi(rowR[1]), rowR[2]);
                    std::shared_ptr<Staff> staffptr = std::make_shared<Staff>(newStaff);
                    DataBase::addRenter(staffptr);

                } else if (rowR[0] == "Student") {
                    Student newStudent = Student(stoi(rowR[1]), rowR[2]);
                    std::shared_ptr<Student> studentptr = std::make_shared<Student>(newStudent);
                    DataBase::addRenter(studentptr);
                }
            }
            else {
                check2++;
            }
        }

    }
    catch(std::exception const& e)
    {
        check2++;
        std::cerr << e.what() <<" for renters.csv file"<<std::endl;
    }
    finRenter.close();

    try {
        finRents.open("../rents.csv", std::ios::in);
        if( !finRents ) throw std::ios::failure( "Error in opening file!" );
        std::vector<string> rowX;
        string lineX, wordX, tempX;
        while (finRents.good()) {
            rowX.clear();
            std::getline(finRents, lineX);
            std::stringstream sX(lineX);
            while (getline(sX, wordX, ',')) {
                rowX.push_back(wordX);
            }
            if (rowX.size() == 2) {//check czy ma odpowiednia ilosc wartosci w linii
                Rent newRent;
                newRent.setRent(DataBase::getItem(stoi(rowX[0])), DataBase::getRenter(stoi(rowX[1])));
                manager.addRent(newRent);
            }
            else {
                check3++;
            }
        }
    }
    catch(std::exception const& e)
    {
        check3++;
        std::cerr << e.what() <<" for rents.csv file"<<std::endl;
    }
    finRents.close();

    if(check1==0){
        if(check2==0) {
            if(check3==0) std::cout<<"Database loaded!"<<std::endl;
            else std::cout<<"Rents File corrupted! "<<std::endl;

        }
        else{
            if(check3==0) std::cout<<"Renters File corrupted! "<<std::endl;
            else std::cout<<"Rents and Renters Files corrupted! "<<std::endl;
        }
    }
    else {
        if(check2==0){
            if(check3==0) std::cout<<"Items File corrupted! "<<std::endl;
            else std::cout<<"Rents and Items Files corrupted!"<<std::endl;
        }
        else{
            if(check3==0) std::cout<<"Items and Renters File corrupted! "<<std::endl;
            else std::cout<<"All files corrupted! "<<std::endl;
        }
    }
}

void DataBase::saveFile(RentingManager &manager) {
    std::ofstream foutRents;
    try {
        foutRents.open("../rents.csv", std::ios::out | std::ios::trunc);
        if( !foutRents ) throw std::ios::failure( "Error in opening file!" );
        for(int z=0;z<manager.getSize()-1;z++){
            foutRents<<manager.getRent(z)->getItem()->getID()-1<<","<<manager.getRent(z)->getRenter()->getID()-1<<std::endl;
        }
        foutRents<<manager.getRent(manager.getSize()-1)->getItem()->getID()-1<<","<<manager.getRent(manager.getSize()-1)->getRenter()->getID()-1;
    }
    catch(std::exception const& e)
    {
        std::cerr << e.what() <<" for items.csv file"<<std::endl;
    }
    foutRents.close();
}

void DataBase::addRenter(renter newRenter) {
    DataBase::renters.push_back(newRenter);

}

void DataBase::addItem(item newItem) {
    DataBase::items.push_back(newItem);
}

renter DataBase::getRenter(int id) {
    return renters.at(id);
}

item DataBase::getItem(int id) {
    return items.at(id);
}

int DataBase::getRentersSize() {
    return renters.size();
}

int DataBase::getItemsSize() {
    return items.size();
}
