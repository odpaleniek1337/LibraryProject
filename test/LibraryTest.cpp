#include <boost/test/unit_test.hpp>

#include "RentingManager.h"
#include "Staff.h"
#include "Book.h"
#include "Item.h"
#include "Rent.h"
#include "Renter.h"
#include <Movie.h>
#include <Student.h>
#include <Other.h>

BOOST_AUTO_TEST_SUITE(LibraryTests)

    BOOST_AUTO_TEST_CASE(testCreateObject_Movie_getID) {
        Movie film=Movie(1,"Spiderman","Tarantino",2);
        BOOST_CHECK_EQUAL(film.getID(), 1);
    }

    BOOST_AUTO_TEST_CASE(testCreateObject_Student_getID) {
        Student student=Student(2,"Michal");
        BOOST_CHECK_EQUAL(student.getID(), 2);
    }

    BOOST_AUTO_TEST_CASE(testCreateObject_Movie_getDirector) {
        Movie film=Movie(1,"Spiderman","Tarantino",2);
        BOOST_CHECK_EQUAL(film.getDirector(), "Tarantino");
    }

    BOOST_AUTO_TEST_CASE(testCreateObject_Book_getAuthor) {
        Book lecture=Book(1,"Dziady","Mickiewicz",2);
        BOOST_CHECK_EQUAL(lecture.getAuthor(), "Mickiewicz");
    }

    BOOST_AUTO_TEST_CASE(testCreateObject_rentAndRentingManager_getSize) {
        Movie film=Movie(1,"Spiderman","Tarantino",2);
        std::shared_ptr<Movie> movieptr = std::make_shared<Movie>(film);
        Student student=Student(2,"Michal");
        std::shared_ptr<Student> studentptr = std::make_shared<Student>(student);
        Rent rent1;
        rent1.setRent(movieptr,studentptr);
        RentingManager manager;
        manager.addRent(rent1);
        BOOST_CHECK_EQUAL(manager.getSize(), 1);
    }

BOOST_AUTO_TEST_SUITE_END()

