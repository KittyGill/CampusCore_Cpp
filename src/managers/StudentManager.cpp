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
    for (Student& student : students)
    {
        if (student.getId() == id)
        {
            return &student;
        }
    }

    return nullptr;
}

bool StudentManager::updateStudent(int id, const Student& updatedStudent)
{
    Student* student = searchStudent(id);

    if (student != nullptr)
    {
        *student = updatedStudent;
        return true;
    }

    return false;
}

bool StudentManager::deleteStudent(int id)
{
    for (auto it = students.begin(); it != students.end(); ++it)
    {
        if (it->getId() == id)
        {
            students.erase(it);
            return true;
        }
    }

    return false;
}