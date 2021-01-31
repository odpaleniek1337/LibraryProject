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

    finBook.open("books.csv", ios::in);
    finRenter.open("renters.csv", ios::in);

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

        if (rowB[0] == "Book") {
            Book book1 = Book(stoi(rowB[1]), rowB[2], rowB[3], stoi(rowB[4]));
            shared_ptr<Book> bookptr = make_shared<Book>(book1);
            if (rowR[0] == "Staff") {
                Staff staff(stoi(rowR[1]), rowR[2]);
                shared_ptr<Staff> staffptr = make_shared<Staff>(staff);
                rent1.setRent(bookptr, staffptr);
            }
            if (rowR[0] == "Student") {

                // Print the found data
                Student student(stoi(rowR[1]), rowR[2]);
                shared_ptr<Student> studentptr = make_shared<Student>(student);
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

                // Print the found data
                Staff staff(stoi(rowR[1]), rowR[2]);
                shared_ptr<Staff> staffptr = make_shared<Staff>(staff);
                rent1.setRent(movieptr, staffptr);
            }
            if (rowR[0] == "Student") {

                // Print the found data
                Student student(stoi(rowR[1]), rowR[2]);
                shared_ptr<Student> studentptr = make_shared<Student>(student);
                rent1.setRent(movieptr, studentptr);
            }
            if (rowR[0] == "Other") {

                // Print the found data
                Other wojtek(stoi(rowR[1]), rowR[2]);
                std::shared_ptr<Other> otherptr = std::make_shared<Other>(wojtek);
                rent1.setRent(movieptr, otherptr);
            }
        }
        pointer.addRent(rent1);
    }
}

int main(int argc, char *argv[]) {
    //RentingManager es;
    //read_Rents(es);
    /*time_t borrowedTime = time(NULL);
    struct tm * time = localtime(&borrowedTime);
    std::cout<<asctime(time)<<std::endl;*/
    /*Book ksiega = Book(13,"Kordian", "Adam Malysz", 5);
    Staff maciek = Staff(1, "Maciek");
    Rent rent1;
    std::shared_ptr<Book> ksiazkawojtka = std::make_shared<Book>(ksiega);
    std::shared_ptr<Staff>maciekptr = std::make_shared<Staff>(maciek);
    rent1.setRent(ksiazkawojtka,maciekptr);
    es.addRent(rent1);
    es.deleteRent(1);*/
    QApplication app(argc, argv);
    QWidget window;
    window.resize(1080, 720);
    window.show();
    window.setWindowTitle(QApplication::translate("childwidget", "Library"));
    QLabel *users = new QLabel(QApplication::translate("childwidget", "List of Users"), &window);
    users->show();
    return app.exec();
    //es.deleteRent(2);
}
