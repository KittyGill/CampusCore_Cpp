#include "Student.h"

Student::Student()
{
    id = 0;
    name = "";
    age = 0;
    batch = "";
    currentSemester = 0;
    cgpa = 0.0f;
}

Student::Student(int id,
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
void Student::setId(int id)
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

int Student::getId() const
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

