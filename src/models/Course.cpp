#include "Course.h"
#include <iostream>

Course::Course()
{
    courseCode = "";
    name = "";
    creditHours = 0;
    courseType = CourseType::Mandatory;
    prerequisiteCourseCode = "";
    tuitionFee = 0;
}

Course::Course(const std::string& courseCode,
               const std::string& name,
               int creditHours,
               CourseType courseType,
               const std::string& prerequisiteCourseCode,
               int tuitionFee)
{
    this->courseCode = courseCode;
    this->name = name;
    this->creditHours = creditHours;
    this->courseType = courseType;
    this->prerequisiteCourseCode = prerequisiteCourseCode;
    this->tuitionFee = tuitionFee;
}

// Setters
void Course::setCourseCode(const std::string& courseCode)
{
    this->courseCode = courseCode;
}

void Course::setName(const std::string& name)
{
    this->name = name;
}

void Course::setCreditHours(int creditHours)
{
    this->creditHours = creditHours;
}

void Course::setCourseType(CourseType courseType)
{
    this->courseType = courseType;
}

void Course::setPrerequisiteCourseCode(const std::string& prerequisiteCourseCode)
{
    this->prerequisiteCourseCode = prerequisiteCourseCode;
}

void Course::setTuitionFee(int tuitionFee)
{
    this->tuitionFee = tuitionFee;
}
    
// Getters

std::string Course::getCourseCode() const
{
    return courseCode;
}

std::string Course::getName() const
{
    return name;
}

int Course::getCreditHours() const
{
    return creditHours;
}

CourseType Course::getCourseType() const
{
    return courseType;
}

std::string Course::getPrerequisiteCourseCode() const
{
    return prerequisiteCourseCode;
}

int Course::getTuitionFee() const
{
    return tuitionFee;
}

void Course::displayCourse() const
{
    std::cout << "Inside displayCourses()" << std::endl;

    std::cout << "Course Code: " << courseCode << std::endl;
    std::cout << "Course Name: " << name << std::endl;
    std::cout << "Credit Hours: " << creditHours << std::endl;
    std::cout << "Course Type: " << static_cast<int>(courseType) << std::endl;
    std::cout << "Prerequisite Course Code: " << prerequisiteCourseCode << std::endl;
    std::cout << "Tuition Fee: " << tuitionFee << std::endl;
    std::cout << "------------------------" << std::endl;
}
