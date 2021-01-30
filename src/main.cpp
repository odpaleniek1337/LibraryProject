#include <iostream>
#include "time.h"
#include "RentingManager.h"
#include "Staff.h"
#include "Book.h"
#include <fstream>
#include <vector>
#include "Rent.h"
#include <sstream>
#include <string>
#include <Movie.h>
#include <Student.h>
#include <Other.h>

using namespace std;

void read_Rents(RentingManager &pointer) {

    // File pointer
    fstream finBook, finRenter;

    // Open an existing file
    finBook.open("books.csv", ios::in);
    finRenter.open("renters.csv", ios::in);

    // Read the Data from the file
    // as String Vector
    vector<string> rowB;
    vector<string> rowR;
    string lineB, wordB, tempB;
    string lineR, wordR, tempR;

    while (finBook.good() && finRenter.good()) {
        Rent rent1;
        rowB.clear();
        rowR.clear();

        // read an entire row and
        // store it in a string variable 'line'
        getline(finBook, lineB);
        getline(finRenter, lineR);

        // used for breaking words
        stringstream sB(lineB);
        stringstream sR(lineR);

        // read every column data of a row and
        // store it in a string variable, 'word'
        while (getline(sB, wordB, ',')) {

            // add all the column data
            // of a row to a vector
            rowB.push_back(wordB);
        }
        while (getline(sR, wordR, ',')) {

            // add all the column data
            // of a row to a vector
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
            // Print the found data
            Book book1 = Book(stoi(rowB[1]), rowB[2], rowB[3], stoi(rowB[4]));
            shared_ptr<Book> bookptr = make_shared<Book>(book1);
            if (rowR[0] == "Staff") {
                Staff palenie(stoi(rowR[1]), rowR[2]);
                shared_ptr<Staff> staffptr = make_shared<Staff>(palenie);
                rent1.setRent(bookptr, staffptr);
            }
            if (rowR[0] == "Student") {

                // Print the found data
                Student debil(stoi(rowR[1]), rowR[2]);
                shared_ptr<Student> studentptr = make_shared<Student>(debil);
                rent1.setRent(bookptr, studentptr);
            }
            if (rowR[0] == "Other") {

                // Print the found data
                Other wojtek(stoi(rowR[1]), rowR[2]);
                std::shared_ptr<Other> otherptr = std::make_shared<Other>(wojtek);
                rent1.setRent(bookptr, otherptr);
            }
        }
        if (rowB[0] == "Movie") {

            // Print the found data
            Movie movie1 = Movie(stoi(rowB[1]), rowB[2], rowB[3], stoi(rowB[4]));
            shared_ptr<Movie> movieptr = make_shared<Movie>(movie1);
            if (rowR[0] == "Staff") {

                // Print the found data
                Staff palenie(stoi(rowR[1]), rowR[2]);
                shared_ptr<Staff> staffptr = make_shared<Staff>(palenie);
                rent1.setRent(movieptr, staffptr);
            }
            if (rowR[0] == "Student") {

                // Print the found data
                Student debil(stoi(rowR[1]), rowR[2]);
                shared_ptr<Student> studentptr = make_shared<Student>(debil);
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

int main() {
    RentingManager es;
    /*vector<Item> item;
    Book ksiega = Book(13,"Kordian", "Adam Malysz", 5);
    item.push_back(ksiega);
    for(int i=0;i<item.size();i++){
        //create(item[i]);
    }
    //es.addRent(item);
    Staff maciek = Staff(1,"Maciek");
    Rent rent1;
    std::shared_ptr<Staff>maciekptr = std::make_shared<Staff>(maciek);
    rent1.setRent(ksiega,maciekptr);*/


    RentingManager *ptr = &es;
    read_Rents(es);
    es.deleteRent(1);
    es.deleteRent(2);

    /*std::cout<<wojtek.getAuthor()<<std::endl;
    std::cout<<wojtek.getID()<<std::endl;
    //std::cout<<wojtek.getBorrowedTime()<<std::endl;
    std::cout<<wojtek.getQuantity()<<std::endl;
    //std::cout<<wojtek.getTitle()<<std::endl;
    Staff maciek = Staff(1, "Maciek");
    std::cout<<maciek.getCurrentItems()<<std::endl;
    std::cout<<maciek.toString()<<std::endl;
    std::cout<<maciek.getName()<<std::endl;
    std::cout<<maciek.getID()<<std::endl;
    */
    std::cout << "Hello, World!" << std::endl;
    return 0;

}