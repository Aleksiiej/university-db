cmake_minimum_required(VERSION 3.11.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(university-db)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)

set(SRC_LIST
    main.cpp
    Database.cpp
    Person.cpp
    Student.cpp
    Employee.cpp
    PESELValidator.cpp
    RecordGenerator.cpp
    Menu.cpp
)

set(SRC_LIST_UT
    Database.cpp
    Person.cpp
    Student.cpp
    Employee.cpp
    PESELValidator.cpp
    RecordGenerator.cpp
    Menu.cpp
)

add_executable(${PROJECT_NAME} ${SRC_LIST})
target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Wpedantic -Wextra -Werror)

enable_testing()
include(GoogleTest)
add_executable(${PROJECT_NAME}-ut ${SRC_LIST_UT} test/DatabaseTest.cpp)
target_link_libraries(${PROJECT_NAME}-ut gtest_main)
add_test(NAME tests COMMAND ${PROJECT_NAME}-ut)