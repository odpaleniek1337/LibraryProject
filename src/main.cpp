#include <iostream>
#include "time.h"
#include "RentingManager.h"
#include "Staff.h"
#include "Book.h"
#include <fstream>
#include <vector>
#include <typeinfo>
#include "Rent.h"
#include <sstream>
#include <string>
#include <Movie.h>
#include <Student.h>
#include <Other.h>


using namespace std;


void read_book(RentingManager &pointer) {

    // File pointer
    fstream fin;

    // Open an existing file
    fin.open("books.csv", ios::in);

    if(!fin.is_open()) throw std::runtime_error("Could not open file");
    Rent rent1;
        // Read the Data from the file
        // as String Vector
        vector<string> row;
        string word, temp;
        while (fin >> temp) {
            row.clear();
            // read an entire row and
            // store it in a string variable 'line'
            //getline(fin, line);
            //cout<<"chuj4"<<endl;
            // used for breaking words
            //stringstream s(line);
            //cout<<"chuj5"<<endl;
            // read every column data of a row and
            // store it in a string variable, 'word'
            while (getline(fin, word,',')) {

                // add all the column data
                // of a row to a vector
                row.push_back(word);
            }
                                                                /*for (int i=0;i<row.size();i++)
                                                                {
                                                                    cout<<i<<": "<<row[i]<<endl;
                                                                }*/
                if (row[0] == "\nBook") {
                    // Print the found data
                    Book book1 = Book(1, row[2], row[3], stoi(row[4]));
                    shared_ptr<Book> bookptr = make_shared<Book>(book1);
                        if (row[5] == "\nStaff") {
                            Staff palenie(1, row[1]);
                            shared_ptr<Staff> staffptr = make_shared<Staff>(palenie);
                            rent1.setRent(bookptr, staffptr);
                        }
                        if (row[0] == "Student") {

                            // Print the found data
                            Student debil(1, row[1]);
                            shared_ptr<Student> studentptr = make_shared<Student>(debil);
                            rent1.setRent(bookptr, studentptr);
                        }
                        if (row[0] == "Other") {

                            // Print the found data
                            Other wojtek(1, row[1]);
                            std::shared_ptr<Other> otherptr = std::make_shared<Other>(wojtek);
                            rent1.setRent(bookptr, otherptr);
                        }
                    //}
                }
                if (row[0] == "Movie") {

                    // Print the found data
                    Movie movie1 = Movie(1, row[2], row[3], stoi(row[4]));
                    shared_ptr<Movie> movieptr = make_shared<Movie>(movie1);
                        if (row[0] == "Staff") {

                            // Print the found data
                            Staff palenie(1, row[1]);
                            shared_ptr<Staff> staffptr = make_shared<Staff>(palenie);
                            rent1.setRent(movieptr, staffptr);
                        }
                        if (row[0] == "Student") {

                            // Print the found data
                            Student debil(1, row[1]);
                            shared_ptr<Student> studentptr = make_shared<Student>(debil);
                            rent1.setRent(movieptr, studentptr);
                        }
                        if (row[0] == "Other") {

                            // Print the found data
                            Other wojtek(1, row[1]);
                            std::shared_ptr<Other> otherptr = std::make_shared<Other>(wojtek);
                            rent1.setRent(movieptr, otherptr);
                        }
                }
        }
    pointer.addRent(rent1);
    cout<<rent1.getRenter()->getID()<<endl;
    cout<<rent1.getItem()->getID()<<endl;
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
    read_book(es);
    es.deleteRent(1);
    //read_record();

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