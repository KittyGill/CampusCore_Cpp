// main.cpp is currently being used for testing purposes. The final version of the main.cpp file will be used to run the application.
#include <iostream>
#include "models/Student.h"
#include "managers/StudentManager.h"
#include "models/Faculty.h"
#include "managers/FacultyManager.h"
#include "utils/Validation.h"

    StudentManager manager;
    FacultyManager facultyManager;

int main()
{
    std::cout << "Program Started!" << std::endl;

    int choice;

    //Generic variables for both Student and Faculty
    std::string id;
    std::string name;
    int age;
    //Student variables
    std::string batch;
    int semester;
    float cgpa;
    //Faculty variables
    std::string department;
    std::string joiningDate;

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
        std::cout << "6. Add Faculty\n";
        std::cout << "7. View Faculties\n";
        std::cout << "8. Search Faculty\n";
        std::cout << "9. Update Faculty\n";
        std::cout << "10. Delete Faculty\n";
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

            case 6:
            {
                std::cout << "Add Faculty Selected.\n";

                // Clear the newline left by std::cin >> choice
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                while (true)
                {
                    std::cout << "Enter Faculty ID: ";
                    std::getline(std::cin, id);

                    if (Validation::isValidFacultyID(id))
                        break;

                    std::cout << "Invalid Faculty ID! Please enter again.\n";
                }

                while (true)
                {
                    std::cout << "Enter Faculty Name: ";
                    std::getline(std::cin, name);

                    if (Validation::isValidName(name))
                        break;

                    std::cout << "Invalid Faculty Name! Please enter again.\n";
                }

                while (true)
                {
                    std::cout << "Enter Faculty Age: ";
                    std::cin >> age;

                    if (Validation::isValidAge(age))
                        break;

                    std::cout << "Invalid Faculty Age! Please enter again.\n";
                }

                while (true)
                {
                    std::cout << "Enter Faculty Department: ";
                    std::cin.ignore();
                    std::getline(std::cin, department);
                    
                    if (Validation::isValidDepartment(department))
                        break;
                    std::cout << "Invalid Faculty Department! Please enter again.\n";
                }

                while (true)
                {
                    std::cout << "Enter Faculty Joining Date (YYYY-MM-DD): ";
                    std::getline(std::cin, joiningDate);
                    
                    if (Validation::isValidJoiningDate(joiningDate))
                        break;
                    std::cout << "Invalid Faculty Joining Date! Please enter again.\n";
                }

                Faculty faculty(id, name, age, department, joiningDate);
                facultyManager.addFaculty(faculty);
    
                break;
            }

            case 7:
            {
                std::cout << "View Faculties Selected.\n";
                facultyManager.viewFaculties();
                break;
            }

            case 8:
            {
                std::cout << "Search Faculty Selected.\n";
                std::cout << "Enter Faculty ID to search: ";
                std::cin >> id;
                Faculty* foundFaculty = facultyManager.searchFaculty(id);
                if (foundFaculty != nullptr)
                {
                    std::cout << "Faculty Found!" << std::endl;
                    foundFaculty->displayFaculty();
                }
                else
                {
                    std::cout << "Faculty not found." << std::endl;
                }
                break;
            }

            case 9:
            {
                std::cout << "Update Faculty Selected.\n";
                std::cout << "Enter Faculty ID to update: ";
                std::cin.ignore();
                std::getline(std::cin, id);
                std::cout << "Enter updated Faculty Name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "Enter updated Faculty Age: ";
                std::cin >> age;
                std::cout << "Enter updated Faculty Department: ";
                std::cin.ignore();
                std::getline(std::cin, department);
                std::cout << "Enter updated Faculty Joining Date (YYYY-MM-DD): ";
                std::cin.ignore();
                std::getline(std::cin, joiningDate);
                Faculty updatedFaculty(id, name, age, department, joiningDate);
                facultyManager.updateFaculty(id, updatedFaculty);
                break;
            }

            case 10:
            {
                std::cout << "Delete Faculty Selected.\n";
                std::cout << "Enter Faculty ID to delete: ";
                std::cin >> id;
                facultyManager.deleteFaculty(id);
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


    return 0;
}