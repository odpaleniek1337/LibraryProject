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

void DataBase::readFile() {
    std::fstream finItem, finRenter;
    int check1 = 0;
    int check2 = 0;
    finItem.open("../items.csv", std::ios::in);
    std::vector<string> rowI;
    string lineI, wordI, tempI;
    try {
        while (finItem.good()) {
            rowI.clear();
            std::getline(finItem, lineI);
            std::stringstream sI(lineI);
            while (getline(sI, wordI, ',')) {
                rowI.push_back(wordI);
            }
            /*for (int i=0;i<rowI.size();i++)
            {
                std::cout<<rowI[i]<<" ";
            }
            std::cout<<std::endl;*/
            if (rowI.size() == 5) {//check czy ma odpowiednia ilosc wartosci w linii
                if (rowI[0] == "Book") {
                    Book newBook = Book(stoi(rowI[1]), rowI[2], rowI[3], stoi(rowI[4]));
                    std::shared_ptr<Book> bookptr = std::make_shared<Book>(newBook);
                    DataBase::addItem(bookptr);
                } else if (rowI[0] == "Movie") {
                    Movie newMovie = Movie(stoi(rowI[1]), rowI[2], rowI[3], stoi(rowI[4]));
                    std::shared_ptr<Movie> movieptr = std::make_shared<Movie>(newMovie);
                    DataBase::addItem(movieptr);
                }
            } else {
                check1++;
            }
        }
    }
    catch(...) {
        std::cout<<"Something is wrong with files!"<<std::endl;
    }

    finItem.close();

    finRenter.open("../renters.csv", std::ios::in);
    std::vector<string> rowR;
    string lineR, wordR, tempR;
    try {
        while (finRenter.good()) {
            rowR.clear();
            std::getline(finRenter, lineR);
            std::stringstream sR(lineR);
            while (getline(sR, wordR, ',')) {
                rowR.push_back(wordR);
            }
            /*for (int i=0;i<rowR.size();i++)
            {
                std::cout<<rowR[i]<<" ";
            }
            std::cout<<std::endl;*/
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
            } else {
                check2++;
            }
        }
    }
    catch(...) {
        std::cout<<"Something is wrong with files!"<<std::endl;
    }

    finRenter.close();
    if(check1==0){
        if(check2==0) std::cout<<"Database loaded!"<<std::endl;
        else{
            std::cout<<"Renters File corrupted! "<<check2<<" rows corrupted!"<<std::endl;
        }
    }
    else {
        if(check2==0){
            std::cout<<"Items File corrupted! "<<check1<<" rows corrupted!"<<std::endl;
        }
        else{
            std::cout<<"Both Files corrupted!"<<std::endl;
        }
    }
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
