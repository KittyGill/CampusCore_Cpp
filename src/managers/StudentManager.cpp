#include <iostream>
#include "StudentManager.h"
#include "../utils/Validation.h"

StudentManager::StudentManager()
{

}

bool StudentManager::addStudent(const Student& student)
{
    if (!validateStudent(student))
    {   
        std::cout << "validateStudent() called\n"; 
        return false;
    }
    students.push_back(student);

    std::cout << "Student added!" << std::endl;
    std::cout << "Total students: " << students.size() << std::endl;
    return true;
}

void StudentManager::viewStudents() const
{
    std::cout << "Inside viewStudents()" << std::endl;

    for (const Student& student : students)
    {
        student.displayStudent();
    }
}

Student* StudentManager::searchStudent(const std::string& id)
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

bool StudentManager::updateStudent(const std::string& id, const Student& updatedStudent)
{
    Student* student = searchStudent(id);

    if (student != nullptr)
    {
        *student = updatedStudent;
        return true;
    }

    return false;
}

bool StudentManager::deleteStudent(const std::string& id)
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

// Validation function to check if the student data is valid
bool StudentManager::validateStudent(const Student& student)
{
    if (!Validation::isValidStudentID(student.getId()))
    {
        std::cout << "Invalid student ID: " << student.getId() << std::endl;
        return false;
    }

    if (!Validation::isValidName(student.getName()))
    {
        std::cout << "Invalid student name: " << student.getName() << std::endl;
        return false;
    }

    if (!Validation::isValidAge(student.getAge()))
    {
        std::cout << "Invalid student age: " << student.getAge() << std::endl;
        return false;
    }

    if (!Validation::isValidBatch(student.getBatch()))
    {
        std::cout << "Invalid student batch: " << student.getBatch() << std::endl;
        return false;
    }

    if (!Validation::isValidSemester(student.getCurrentSemester()))
    {
        std::cout << "Invalid student semester: " << student.getCurrentSemester() << std::endl;
        return false;
    }

    if (!Validation::isValidCGPA(student.getCGPA()))
    {
        std::cout << "Invalid student CGPA: " << student.getCGPA() << std::endl;
        return false;
    }

   
        // return false;

    if (!Validation::isValidName(student.getName()))
        return false;

    if (!Validation::isValidAge(student.getAge()))
        return false;

    if (!Validation::isValidBatch(student.getBatch()))
        return false;

    if (!Validation::isValidSemester(student.getCurrentSemester()))
        return false;

    if (!Validation::isValidCGPA(student.getCGPA()))
        return false;

    return true;
}