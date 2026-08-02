#include "Faculty.h"

Faculty::Faculty()
{
    id = 0;
    name = "";
    age = 0;
    department = "";
    joiningDate = "";
}

Faculty::Faculty(int id,
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
void Faculty::setId(int id)
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

int Faculty::getId() const
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

