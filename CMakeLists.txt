cmake_minimum_required(VERSION 3.17)
project(Library)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(Library
        include/Movie.h
        include/Book.h
        include/BorrowedItem.h
        include/RentingManager.h
        include/Renter.h
        include/Other.h
        include/Student.h
        include/Staff.h
        include/TimeManager.h
        src/main.cpp src/Book.cpp src/BorrowedItem.cpp src/Movie.cpp src/Other.cpp src/Renter.cpp src/RentingManger.cpp src/Staff.cpp src/Student.cpp src/TimeManager.cpp include/Rent.h src/Rent.cpp)

target_link_libraries(${PROJECT_NAME})
