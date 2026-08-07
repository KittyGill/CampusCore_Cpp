// main.cpp is currently being used for testing purposes. The final version of the main.cpp file will be used to run the application.
#include <iostream>
#include "managers/StudentManager.h"
#include "models/Student.h"
#include "utils/Validation.h"
    StudentManager manager;

int main()
{
    std::cout << "Program Started!" << std::endl;

    int choice;

    std::string id;
    std::string name;
    int age;
    std::string batch;
    int semester;
    float cgpa;

    do
    {
        std::cout << "\n==================================\n";
        std::cout << "        CampusCore v0.1\n";
        std::cout << "==================================\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. View Students\n";
        std::cout << "3. Search Student\n";
        std::cout << "4. Update Student\n";
        std::cout << "5. Delete Student\n";
        std::cout << "0. Exit\n";
        std::cout << "\nEnter your choice: ";

        std::cin >> choice;

        switch(choice)
        {
            case 1:
            {
                std::cout << "Add Student Selected.\n";

                // Clear the newline left by std::cin >> choice
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                while (true)
                {
                    std::cout << "Enter Student ID: ";
                    std::getline(std::cin, id);

                    if (Validation::isValidStudentID(id))
                        break;

                    std::cout << "Invalid Student ID! Please enter again.\n";
                }

                while (true)
                {
                    std::cout << "Enter Student Name: ";
                    std::getline(std::cin, name);

                    if (Validation::isValidName(name))
                        break;

                    std::cout << "Invalid Student Name! Please enter again.\n";
                }

                while (true)
                {
                    std::cout << "Enter Student Age: ";
                    std::cin >> age;

                    if (Validation::isValidAge(age))
                        break;

                    std::cout << "Invalid Student Age! Please enter again.\n";
                }

                while (true)
                {
                    std::cout << "Enter Student Batch: ";
                    std::cin.ignore();
                    std::getline(std::cin, batch);
                    
                    if (Validation::isValidBatch(batch))
                        break;
                    std::cout << "Invalid Student Batch! Please enter again.\n";
                }

                while (true)
                {
                    std::cout << "Enter Student Semester: ";
                    std::cin >> semester;

                    if (Validation::isValidSemester(semester))
                        break;

                    std::cout << "Invalid Student Semester! Please enter again.\n";
                }

                while (true)
                {
                    std::cout << "Enter Student CGPA: ";
                    std::cin >> cgpa;

                    if (Validation::isValidCGPA(cgpa))
                        break;

                    std::cout << "Invalid Student CGPA! Please enter again.\n";
                }

                Student student(id, name, age, batch, semester, cgpa);
                manager.addStudent(student);
    
                break;
            }

            case 2:
            {
                std::cout << "View Students Selected.\n";
                manager.viewStudents();
                break;
            }

            case 3:
            {
                std::cout << "Search Student Selected.\n";
                std::cout << "Enter Student ID to search: ";
                std::cin >> id;
                Student* foundStudent = manager.searchStudent(id);
                if (foundStudent != nullptr)
                {
                    std::cout << "Student Found!" << std::endl;
                    foundStudent->displayStudent();
                }
                else
                {
                    std::cout << "Student not found." << std::endl;
                }
                break;
            }

            case 4:
            {
                std::cout << "Update Student Selected.\n";
                std::cout << "Enter Student ID to update: ";
                std::cin.ignore();
                std::getline(std::cin, id);
                std::cout << "Enter updated Student Name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "Enter updated Student Age: ";
                std::cin >> age;
                std::cout << "Enter updated Student Batch: ";
                std::cin.ignore();
                std::getline(std::cin, batch);
                std::cout << "Enter updated Student Semester: ";
                std::cin >> semester;
                std::cout << "Enter updated Student CGPA: ";
                std::cin >> cgpa;
                Student updatedStudent(id, name, age, batch, semester, cgpa);
                manager.updateStudent(id, updatedStudent);
                break;
            }

            case 5:
            {
                std::cout << "Delete Student Selected.\n";
                std::cout << "Enter Student ID to delete: ";
                std::cin >> id;
                manager.deleteStudent(id);
                break;
            }

            case 0:
            {
                std::cout << "Exiting CampusCore...\n";
                break;
            }

            default:
            {
                std::cout << "Invalid Choice!\n";
            }
        }

    } while(choice != 0);

    //reuse this in the cases
    // Student student1(
    //     101,
    //     "Christopher",
    //     20,
    //     "BSCS",
    //     5,
    //     3.80
    // );

    // Student student2(
    //     102,
    //     "John",
    //     21,
    //     "BSCS",
    //     5,
    //     3.50
    // );

    // manager.addStudent(student1);
    // manager.addStudent(student2);

    // manager.viewStudents();

    // Student* foundStudent = manager.searchStudent(101);

    // if (foundStudent != nullptr)
    // {
    //     std::cout << "Student Found!" << std::endl;
    //     foundStudent->displayStudent();
    // }
    // else
    // {
    //     std::cout << "Student not found." << std::endl;
    // }


    // Student updatedStudent(
    // 101,
    // "Christopher Gill",
    // 21,
    // "BSCS",
    // 6,
    // 3.95
    // );
    
    // manager.updateStudent(101, updatedStudent);
    // manager.deleteStudent(102);
    // manager.viewStudents();

    return 0;
}