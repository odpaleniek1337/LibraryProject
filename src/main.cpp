#include "RentingManager.h"
#include "DataBase.h"
#include <GUIHandler.h>
#include "Book.h"
#include "Student.h"
#include "Rent.h"


using namespace std;

int main(int argc, char *argv[]) {
    RentingManager manager;
    DataBase base;
    base.readFile();
    /*Book book1 = Book(5,"Tytul","Autor",5);
    Student student1 = Student(5,"Maciek");
    Rent rent1;
    rent1.setRent(std::make_shared<Book>(book1), std::make_shared<Student>(student1));
    manager.addRent(rent1);*/
    //std::cout<<std::asctime(manager.getRent(0)->getTime())<<std::endl;
    //rents cant be seen because there are no rents currently made
    QApplication app(argc, argv);
    GUIHandler myGUI(std::make_shared<DataBase>(base), std::make_shared<RentingManager>(manager));
    myGUI.resize(1080,720);
    myGUI.setWindowTitle(QApplication::translate("main", "Library"));
    myGUI.show();
    return app.exec();
}