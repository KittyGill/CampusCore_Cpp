#include "Faculty.h"
#include <iostream>
Faculty::Faculty()
{
    id = "";
    name = "";
    age = 0;
    department = "";
    joiningDate = "";
}

Faculty::Faculty(const std::string& id,
                 const std::string& name,
                 int age,
                 const std::string& department,
                 const std::string& joiningDate)
{
    this->id = id;
    this->name = name;
    this->age = age;
    this->department = department;
    this->joiningDate = joiningDate;
}

// Setters
void Faculty::setId(const std::string& id)
{
    this->id = id;
}

void Faculty::setName(const std::string& name)
{
    this->name = name;
}

void Faculty::setAge(int age)
{
    this->age = age;
}

void Faculty::setDepartment(const std::string& department)
{
    this->department = department;
}

void Faculty::setJoiningDate(const std::string& joiningDate)
{
    this->joiningDate = joiningDate;
}

// Getters

std::string Faculty::getId() const
{
    return id;
}

std::string Faculty::getName() const
{
    return name;
}

int Faculty::getAge() const
{
    return age;
}

std::string Faculty::getDepartment() const
{
    return department;
}

std::string Faculty::getJoiningDate() const
{
    return joiningDate;
}

const std::vector<std::string> Faculty::getCoursesTeaching() const
{
    return coursesTeaching;
}

void Faculty::displayFaculty() const
{
    std::cout << "Inside viewFaculties()" << std::endl;

    std::cout << "ID: " << id << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Department: " << department << std::endl;
    std::cout << "Joining Date: " << joiningDate << std::endl;
    std::cout << "------------------------" << std::endl;
}
