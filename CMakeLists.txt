<<<<<<< HEAD
cmake_minimum_required(VERSION 3.4)

#Configuration parameters of cmake
=======
cmake_minimum_required(VERSION 3.13)

>>>>>>> 096e9ae... CMakeLists.txt configured. Unit Tests and GUI working properly on Ubuntu
set(CMAKE_CXX_COMPILER g++)#requires g++ to be available on PATH
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

<<<<<<< HEAD
project(Project)
=======
project(Library)
>>>>>>> 096e9ae... CMakeLists.txt configured. Unit Tests and GUI working properly on Ubuntu
enable_language(CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE TRUE)

<<<<<<< HEAD
#Source files here
set(SOURCE_FILES
=======
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

include_directories(include)

add_executable(Library
>>>>>>> 096e9ae... CMakeLists.txt configured. Unit Tests and GUI working properly on Ubuntu
        include/Movie.h
        include/Book.h
        include/Item.h
        include/RentingManager.h
        include/Renter.h
        include/Other.h
        include/Student.h
        include/Staff.h
<<<<<<< HEAD
=======
        include/DataBase.h
>>>>>>> 096e9ae... CMakeLists.txt configured. Unit Tests and GUI working properly on Ubuntu
        src/main.cpp
        src/Book.cpp
        src/Item.cpp
        src/Movie.cpp
        src/Other.cpp
        src/Renter.cpp
        src/RentingManager.cpp
        src/Staff.cpp
        src/Student.cpp
        include/Rent.h
<<<<<<< HEAD
        src/Rent.cpp)

add_executable(Project ${SOURCE_FILES})

target_include_directories(Project PUBLIC include)

#TESTs
=======
        src/Rent.cpp
        src/DataBase.cpp
        )

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)
qt5_use_modules(${PROJECT_NAME} Core Widgets Gui)


target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Core Qt5::Gui)

>>>>>>> 096e9ae... CMakeLists.txt configured. Unit Tests and GUI working properly on Ubuntu
find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

#Test source files here
set(SOURCE_TEST_FILES
        test/LibraryTest.cpp
        test/master.cpp
        src/Book.cpp
        src/Item.cpp
        src/Movie.cpp
        src/Other.cpp
        src/Renter.cpp
        src/RentingManager.cpp
        src/Staff.cpp
        src/Student.cpp
<<<<<<< HEAD
        src/Rent.cpp)
=======
        src/Rent.cpp
        src/DataBase.cpp)
>>>>>>> 096e9ae... CMakeLists.txt configured. Unit Tests and GUI working properly on Ubuntu

add_executable(TestProject ${SOURCE_TEST_FILES})

target_include_directories(TestProject PUBLIC include)

target_link_libraries (TestProject
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

enable_testing()

add_test(NAME Test COMMAND TestProject
        --report_level=detailed
        --log_level=all
        --color_output=yes)

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> --verbose
<<<<<<< HEAD
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
=======
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
>>>>>>> 096e9ae... CMakeLists.txt configured. Unit Tests and GUI working properly on Ubuntu
