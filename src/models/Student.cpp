#include <iostream>
#include "Student.h"

Student::Student()
{
    id = "";
    name = "";
    age = 0;
    batch = "";
    currentSemester = 0;
    cgpa = 0.0f;
}

Student::Student(std::string id,
                 std::string name,
                 int age,
                 std::string batch,
                 int currentSemester,
                 float cgpa)
{
    this->id = id;
    this->name = name;
    this->age = age;
    this->batch = batch;
    this->currentSemester = currentSemester;
    this->cgpa = cgpa;
}

// Setters
void Student::setId(const std::string& id)
{
    this->id = id;
}

void Student::setName(const std::string& name)
{
    this->name = name;
}

void Student::setAge(int age)
{
    this->age = age;
}

void Student::setBatch(const std::string& batch)
{
    this->batch = batch;
}

void Student::setCurrentSemester(int semester)
{
    this->currentSemester = semester;
}

void Student::setCGPA(float cgpa)
{
    this->cgpa = cgpa;
}

// Getters

std::string Student::getId() const
{
    return id;
}

std::string Student::getName() const
{
    return name;
}

int Student::getAge() const
{
    return age;
}

std::string Student::getBatch() const
{
    return batch;
}

int Student::getCurrentSemester() const
{
    return currentSemester;
}

float Student::getCGPA() const
{
    return cgpa;
}

const std::vector<std::string> Student::getRegisteredCourses() const
{
    return registeredCourses;
}

// Display Student should not belong in the models, infact any display function shouldnt, this would be moved to UI classes in future.
void Student::displayStudent() const
{
    std::cout << "Inside viewStudents()" << std::endl;

    std::cout << "ID: " << id << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Batch: " << batch << std::endl;
    std::cout << "Semester: " << currentSemester << std::endl;
    std::cout << "CGPA: " << cgpa << std::endl;
    std::cout << "------------------------" << std::endl;
}