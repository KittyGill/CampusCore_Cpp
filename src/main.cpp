// main.cpp is currently being used for testing purposes. The final version of the main.cpp file will be used to run the application.
#include <iostream>

#include "managers/StudentManager.h"

int main()
{
    std::cout << "Program Started!" << std::endl;

    StudentManager manager;

    Student student1(
        101,
        "Christopher",
        20,
        "BSCS",
        5,
        3.80
    );

    Student student2(
        102,
        "John",
        21,
        "BSCS",
        5,
        3.50
    );

    manager.addStudent(student1);
    manager.addStudent(student2);

    manager.viewStudents();

    Student* foundStudent = manager.searchStudent(101);

    if (foundStudent != nullptr)
    {
        std::cout << "Student Found!" << std::endl;
        foundStudent->displayStudent();
    }
    else
    {
        std::cout << "Student not found." << std::endl;
    }


    Student updatedStudent(
    101,
    "Christopher Gill",
    21,
    "BSCS",
    6,
    3.95
    );
    
    manager.updateStudent(101, updatedStudent);
    manager.deleteStudent(102);
    manager.viewStudents();

    return 0;
}