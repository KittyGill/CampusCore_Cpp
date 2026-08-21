// main.cpp is currently being used for testing purposes. The final version of the main.cpp file will be used to run the application.
#include <iostream>
#include "models/Student.h"
#include "managers/StudentManager.h"
#include "models/Faculty.h"
#include "managers/FacultyManager.h"
#include "models/Course.h"
#include "managers/CourseManager.h"
#include "models/CourseSlot.h"
#include "managers/CourseSlotManager.h"
#include "utils/Validation.h"

    StudentManager manager;
    FacultyManager facultyManager;
    CourseManager courseManager;
    CourseSlotManager courseSlotManager;
int main()
{
    std::cout << "Program Started!" << std::endl;

    int choice;
    int typeChoice;

    //Generic variables for both Student and Faculty
    std::string id;
    std::string name;
    int age;
    //Student variables
    std::string batch;
    int semester;
    float cgpa;
    //Faculty variables
    std::string facultyID;
    std::string department;
    std::string joiningDate;
    //Course Variables
    int creditHours;
    std::string courseCode;
    CourseType courseType;
    std::string prerequisiteCourseCode;
    int tuitionFee;
    //Course Slot Variables
    Days days;
    Time time;
    int availableSeats;
    int classRoom;

    do
    {
        std::cout << "\n==================================\n";
        std::cout << "        CampusCore v0.1\n";
        std::cout << "==================================\n";
        std::cout << "\n1. Add Student\n";
        std::cout << "2. View Students\n";
        std::cout << "3. Search Student\n";
        std::cout << "4. Update Student\n";
        std::cout << "5. Delete Student\n";
        std::cout << "\n6. Add Faculty\n";
        std::cout << "7. View Faculties\n";
        std::cout << "8. Search Faculty\n";
        std::cout << "9. Update Faculty\n";
        std::cout << "10. Delete Faculty\n";
        std::cout << "\n11. Add Course\n";
        std::cout << "12. View Courses\n";
        std::cout << "13. Search Course\n";
        std::cout << "14. Update Course\n";
        std::cout << "15. Delete Course\n";
        std::cout << "16. Add Course Slot\n";
        std::cout << "17. View Course Slots\n";
        std::cout << "18. Search Course Slot\n";
        std::cout << "19. Update Course Slot\n";
        std::cout << "20. Delete Course Slot\n";
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
            
            // Faculty cases
            case 6:
            {
                std::cout << "Add Faculty Selected.\n";

                // Clear the newline left by std::cin >> choice
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                while (true)
                {
                    std::cout << "Enter Faculty ID: ";
                    std::getline(std::cin, facultyID);

                    if (Validation::isValidFacultyID(facultyID))
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

                Faculty faculty(facultyID, name, age, department, joiningDate);
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
                std::cin.ignore();
                std::getline(std::cin, facultyID);
                Faculty* foundFaculty = facultyManager.searchFaculty(facultyID);
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
            
            //Course cases
            case 11:
            {
                std::cout << "Add Course Selected.\n";

                // Clear the newline left by std::cin >> choice
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                while (true)
                {
                    std::cout << "Enter Course Code: ";
                    std::getline(std::cin, courseCode);

                    if (Validation::isValidCourseCode(courseCode))
                        break;

                    std::cout << "Invalid Course Code! Please enter again.\n";
                }

                while (true)
                {
                    std::cout << "Enter Course Name: ";
                    std::getline(std::cin, name);

                    if (Validation::isValidName(name))
                        break;

                    std::cout << "Invalid Course Name! Please enter again.\n";
                }

                while (true)
                {
                    std::cout << "Enter Course Credit Hours: ";
                    std::cin >> creditHours;

                    if (Validation::isValidCreditHours(creditHours))
                        break;

                    std::cout << "Invalid Course Credit Hours! Please enter again.\n";
                }

                while (true)
                {
                    std::cout << "Enter Course Type:\n";
                    std::cout << "1. Mandatory\n";
                    std::cout << "2. Elective\n";
                    std::cout << "Enter choice: ";

                    std::cin >> typeChoice;

                    if (typeChoice == 1)
                    {
                        courseType = CourseType::Mandatory;
                        break;
                    }

                    if (typeChoice == 2)
                    {
                        courseType = CourseType::Elective;
                        break;
                    }

                    std::cout << "Invalid Course Type! Please enter again.\n";
                }

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                while (true)
                {
                    std::cout << "Enter Course Prerequisite: ";
                    std::getline(std::cin, prerequisiteCourseCode);
                    
                    if (Validation::isValidPrerequisiteCourseCode(prerequisiteCourseCode))
                        break;
                    std::cout << "Invalid Course Prerequisite! Please enter again.\n";
                }

                while (true)
                {
                    std::cout << "Enter Course Tuition Fee: ";
                    std::cin >> tuitionFee;

                    if (Validation::isValidTuitionFee(tuitionFee))
                        break;
                    std::cout << "Invalid Course Tuition Fee! Please enter again.\n";
                }


                Course course(courseCode, name, creditHours, courseType, prerequisiteCourseCode, tuitionFee);
                courseManager.addCourse(course);

                break;
            }

            case 12:
            {
                std::cout << "View Courses Selected.\n";
                courseManager.viewCourses();
                break;
            }

            case 13:
            {
                std::cout << "Search Course Selected.\n";
                std::cout << "Enter Course Code to search: ";
                std::cin >> courseCode;
                Course* foundCourse = courseManager.searchCourse(courseCode);
                if (foundCourse != nullptr)
                {
                    std::cout << "Course Found!" << std::endl;
                    foundCourse->displayCourse();
                }
                else
                {
                    std::cout << "Course not found." << std::endl;
                }
                break;
            }

            case 14:
            {
                std::cout << "Update Course Selected.\n";
                std::cout << "Enter Course Code to update: ";
                std::cin.ignore();
                std::getline(std::cin, courseCode);
                std::cout << "Enter updated Course Name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "Enter updated Course Credit Hours: ";
                std::cin >> creditHours;
                std::cout << "Enter updated Course Type:\n";
                std::cout << "1. Mandatory\n";
                std::cout << "2. Elective\n";
                std::cin >> typeChoice;
                if (typeChoice == 1)
                    courseType = CourseType::Mandatory;
                else if (typeChoice == 2)
                    courseType = CourseType::Elective;
                else
                {
                    std::cout << "Invalid Course Type! Defaulting to Mandatory.\n";                    
                    courseType = CourseType::Mandatory;
                }        

                std::cout << "Enter updated Course Prerequisite: ";
                std::cin.ignore();
                std::getline(std::cin, prerequisiteCourseCode);
                std::cout << "Enter updated Course Tuition Fee: ";
                std::cin >> tuitionFee;

                Course updatedCourse(courseCode, name, creditHours, courseType, prerequisiteCourseCode, tuitionFee);
                courseManager.updateCourse(courseCode, updatedCourse);
                break;
            }

            case 15:
            {
                std::cout << "Delete Course Selected.\n";
                std::cout << "Enter CourseCode to delete: ";
                std::cin >> id;
                courseManager.deleteCourse(id);
                break;
            }

            //Course Slot cases
            case 16:
            {
                std::cout << "Add Course Slot Selected.\n";

                // Clear the newline left by std::cin >> choice
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                while (true)
                {
                    std::cout << "Enter Course Slot Code: ";
                    std::getline(std::cin, id);

                    if (Validation::isValidCourseSlotCode(id))
                        break;

                    std::cout << "Invalid Course Slot Code! Please enter again.\n";
                }

                while (true)
                {
                    std::cout << "Enter Course Code: ";
                    std::getline(std::cin, courseCode);

                    if (Validation::isValidCourseCode(courseCode))
                        break;

                    std::cout << "Invalid Course Code! Please enter again.\n";
                }

                while (true)
                {   std::cout << "Enter Days:\n";
                    std::cout << "1. Monday, Wednesday\n";
                    std::cout << "2. Tuesday, Thursday\n";
                    std::cout << "3. Friday, Saturday\n";
                    std::cout << "4. Monday, Wednesday, Friday\n";
                    std::cout << "5. Tuesday, Thursday, Saturday\n";
                    std::cout << "Enter choice: ";

                    std::cin >> typeChoice;

                    if (typeChoice == 1)
                    {
                        days = Days::MonWed;
                        break;
                    }

                    if (typeChoice == 2)
                    {
                        days = Days::TueThu;
                        break;
                    }
                    if (typeChoice == 3)
                    {
                        days = Days::FriSat;
                        break;
                    }
                    if (typeChoice == 4)
                    {
                        days = Days::MonWedFri;
                        break;
                    }
                    if (typeChoice == 5)
                    {
                        days = Days::TueThuSat;
                        break;
                    }

                    std::cout << "Invalid Days! Please enter again.\n";
                }

                while (true)
                {
                    std::cout << "Enter Time:\n";
                    std::cout << "1. Morning_0830_0930\n";
                    std::cout << "2. Morning_0830_1000\n";
                    std::cout << "3. Noon_1200_1300\n";
                    std::cout << "4. Noon_1200_1400\n";
                    std::cout << "5. Afternoon_1400_1500\n";
                    std::cout << "6. Afternoon_1500_1600\n";
                    std::cout << "7. Evening_1600_1700\n";
                    std::cout << "8. Evening_1700_1800\n";
                    std::cout << "Enter choice: ";

                    std::cin >> typeChoice;

                    if (typeChoice == 1)
                    {
                        time = Time::Morning_0830_0930;
                        break;
                    }

                    if (typeChoice == 2)
                    {
                        time = Time::Morning_0830_1000;
                        break;
                    }
                    if (typeChoice == 3)
                    {
                        time = Time::Noon_1200_1300;
                        break;
                    }
                    if (typeChoice == 4)
                    {
                        time = Time::Noon_1200_1400;
                        break;
                    }
                    if (typeChoice == 5)
                    {
                        time = Time::Afternoon_1400_1500;
                        break;
                    }
                    if (typeChoice == 6)
                    {
                        time = Time::Afternoon_1500_1600;
                        break;
                    }
                    if (typeChoice == 7)
                    {
                        time = Time::Evening_1600_1700;
                        break;
                    }
                    if (typeChoice == 8)
                    {
                        time = Time::Evening_1700_1800;
                        break;
                    }

                    std::cout << "Invalid Class Time! Please enter again.\n";
                }

                while (true)
                {
                    std::cout << "Enter ClassRoom: ";
                    std::cin >> classRoom;
                    
                    if (Validation::isValidClassRoom(classRoom))
                        break;
                    std::cout << "Invalid ClassRoom! Please enter again.\n";
                }

                while (true)
                {
                    std::cout << "Enter available Seats: ";
                    std::cin >> availableSeats;
                    
                    if (Validation::isValidSeatsAvailable(availableSeats))
                        break;
                    std::cout << "Invalid available Seats! Please enter again.\n";
                }

                 while (true)
                {
                    std::cout << "Enter Faculty ID: ";
                    std::cin >> facultyID;
                    
                    if (Validation::isValidFacultyID(facultyID))
                        break;
                    std::cout << "Invalid Faculty ID! Please enter again.\n";
                }

                CourseSlot courseSlot(id,courseCode, days, time, classRoom, availableSeats);
                courseSlotManager.addCourseSlot(courseSlot);
    
                break;
            }

            case 17:
            {
                std::cout << "View Course Slots Selected.\n";
                courseSlotManager.viewCourseSlots();
                break;
            }

            case 18:
            {
                std::cout << "Search Course Slot Selected.\n";
                std::cout << "Enter CourseSlot Code to search: ";
                std::cin >> id;
                CourseSlot* foundCourseSlot = courseSlotManager.searchCourseSlot(id);
                if (foundCourseSlot != nullptr)
                {
                    std::cout << "Course Slot Found!" << std::endl;
                    foundCourseSlot->displayCourseSlot();
                }
                else
                {
                    std::cout << "Course Slot not found." << std::endl;
                }
                break;
            }

            case 19:
            {
                std::cout << "Update Course Slot Selected.\n";
                std::cout << "Enter CourseSlot Code to update: ";
                std::cin.ignore();
                std::getline(std::cin, id);
                std::cout << "Enter updated Course Code: ";
                std::cin.ignore();
                std::getline(std::cin, courseCode);
                std::cout << "Enter updated Days: ";
                std::cout << "1. Monday, Wednesday\n";
                std::cout << "2. Tuesday, Thursday\n";
                std::cout << "3. Friday, Saturday\n";
                std::cout << "4. Monday, Wednesday, Friday\n";
                std::cout << "5. Tuesday, Thursday, Saturday\n";
                std::cin >> typeChoice;
                if (typeChoice == 1)
                    days = Days::MonWed;
                else if (typeChoice == 2)
                    days = Days::TueThu;
                else if (typeChoice == 3)
                    days = Days::FriSat;
                else if (typeChoice == 4)
                    days = Days::MonWedFri;
                else if (typeChoice == 5)
                    days = Days::TueThuSat;
                else
                {
                    std::cout << "Invalid Days! Defaulting to Monday, Wendesday.\n";                    
                    days = Days::MonWed;
                }
                std::cout << "Enter updated Time: ";
                std::cout << "1. Morning_0830_0930\n";
                std::cout << "2. Morning_0830_1000\n";
                std::cout << "3. Noon_1200_1300\n";
                std::cout << "4. Noon_1200_1400\n";
                std::cout << "5. Afternoon_1400_1500\n";
                std::cout << "6. Afternoon_1500_1600\n";
                std::cout << "7. Evening_1600_1700\n";
                std::cout << "8. Evening_1700_1800\n";
                std::cin >> typeChoice;
                if (typeChoice == 1)
                    time = Time::Morning_0830_0930;
                else if (typeChoice == 2)
                    time = Time::Morning_0830_1000;
                else if (typeChoice == 3)
                    time = Time::Noon_1200_1300;
                else if (typeChoice == 4)
                    time = Time::Noon_1200_1400;
                else if (typeChoice == 5)
                    time = Time::Afternoon_1400_1500;
                else if (typeChoice == 6)
                    time = Time::Afternoon_1500_1600;
                else if (typeChoice == 7)
                    time = Time::Evening_1600_1700;
                else if (typeChoice == 8)
                    time = Time::Evening_1700_1800;
                else
                {
                    std::cout << "Invalid Time! Defaulting to Morning_0830_0930.\n";
                    time = Time::Morning_0830_0930;
                }
                std::cout << "Enter updated ClassRoom: ";
                std::cin >> classRoom;
                std::cout << "Enter updated Seats Available: ";
                std::cin >> availableSeats;
                std::cout << "Enter updated Faculty ID: ";
                std::getline(std::cin, facultyID);
                CourseSlot updatedCourseSlot(id, courseCode, days, time, classRoom, availableSeats);
                courseSlotManager.updateCourseSlot(id, updatedCourseSlot);
                break;
            }

            case 20:
            {
                std::cout << "Delete Course Slot Selected.\n";
                std::cout << "Enter CourseSlot Code to delete: ";
                std::cin >> id;
                courseSlotManager.deleteCourseSlot(id);
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