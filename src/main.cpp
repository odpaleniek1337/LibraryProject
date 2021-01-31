#include <iostream>
#include "RentingManager.h"
#include "Book.h"
#include "Movie.h"
#include "Staff.h"
#include "Student.h"
#include "Other.h"
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <QApplication>
#include <QtWidgets>

using namespace std;

void read_Rents(RentingManager &pointer) {

    fstream finBook, finRenter;
    int check=0;

    finBook.open("../items.csv", ios::in);
    finRenter.open("../renters.csv", ios::in);

    vector<string> rowB;
    vector<string> rowR;
    string lineB, wordB, tempB;
    string lineR, wordR, tempR;

    while (finBook.good() && finRenter.good()) {
        Rent rent1;
        rowB.clear();
        rowR.clear();

        getline(finBook, lineB);
        getline(finRenter, lineR);

        stringstream sB(lineB);
        stringstream sR(lineR);

        while (getline(sB, wordB, ',')) {
            rowB.push_back(wordB);
        }
        while (getline(sR, wordR, ',')) {
            rowR.push_back(wordR);
        }

        /*for (int i=0;i<rowB.size();i++)
        {
            cout<<rowB[i]<<" ";
        }
        cout<<endl;
        for (int i=0;i<rowR.size();i++)
        {
            cout<<rowR[i]<<" ";
        }
        cout<<endl;*/
        if(rowB.size()!=0 && rowR.size()!=0) {
            if (rowB[0] == "Book") {
                Book book1 = Book(stoi(rowB[1]), rowB[2], rowB[3], stoi(rowB[4]));
                shared_ptr<Book> bookptr = make_shared<Book>(book1);
                if (rowR[0] == "Staff") {
                    Staff palenie(stoi(rowR[1]), rowR[2]);
                    shared_ptr<Staff> staffptr = make_shared<Staff>(palenie);
                    rent1.setRent(bookptr, staffptr);
                }
                if (rowR[0] == "Student") {
                    Student debil(stoi(rowR[1]), rowR[2]);
                    shared_ptr<Student> studentptr = make_shared<Student>(debil);
                    rent1.setRent(bookptr, studentptr);
                }
                if (rowR[0] == "Other") {
                    Other wojtek(stoi(rowR[1]), rowR[2]);
                    std::shared_ptr<Other> otherptr = std::make_shared<Other>(wojtek);
                    rent1.setRent(bookptr, otherptr);
                }
            }
            if (rowB[0] == "Movie") {
                Movie movie1 = Movie(stoi(rowB[1]), rowB[2], rowB[3], stoi(rowB[4]));
                shared_ptr<Movie> movieptr = make_shared<Movie>(movie1);
                if (rowR[0] == "Staff") {
                    Staff palenie(stoi(rowR[1]), rowR[2]);
                    shared_ptr<Staff> staffptr = make_shared<Staff>(palenie);
                    rent1.setRent(movieptr, staffptr);
                }
                if (rowR[0] == "Student") {
                    Student debil(stoi(rowR[1]), rowR[2]);
                    shared_ptr<Student> studentptr = make_shared<Student>(debil);
                    rent1.setRent(movieptr, studentptr);
                }
                if (rowR[0] == "Other") {
                    Other wojtek(stoi(rowR[1]), rowR[2]);
                    std::shared_ptr<Other> otherptr = std::make_shared<Other>(wojtek);
                    rent1.setRent(movieptr, otherptr);
                }
            }
            pointer.addRent(rent1);
        }
        else
        {
            std::cout<<"File is empty!"<<std::endl;
            check++;

        }
    }
    if(check==0) std::cout<<"Database loaded!"<<std::endl;
}

int main(int argc, char *argv[]) {
    RentingManager es;
    read_Rents(es);
    //es.deleteRent(1);
    //es.deleteRent(2);

    QApplication app(argc, argv);
    QWidget window;
    window.resize(1080, 720);
    window.show();
    window.setWindowTitle(QApplication::translate("childwidget", "Library"));
    QLabel *users = new QLabel(QApplication::translate("childwidget", "List of Users"), &window);
    users->show();
    return app.exec();
}