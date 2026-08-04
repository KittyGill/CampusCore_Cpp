#include <iostream>
#include "StudentManager.h"

StudentManager::StudentManager()
{

}

void StudentManager::addStudent(const Student& student)
{
    students.push_back(student);

    std::cout << "Student added!" << std::endl;
    std::cout << "Total students: " << students.size() << std::endl;
}

void StudentManager::viewStudents() const
{
    std::cout << "Inside viewStudents()" << std::endl;

    for (const Student& student : students)
    {
        student.displayStudent();
    }
}

Student* StudentManager::searchStudent(int id)
{
    return nullptr;
}

bool StudentManager::updateStudent(int id,
                                   const Student& updatedStudent)
{
    return false;
}

bool StudentManager::deleteStudent(int id)
{
    return false;
}