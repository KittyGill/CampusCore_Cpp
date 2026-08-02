#include "Course.h"

Course::Course()
{
    courseCode = "";
    courseName = "";
    creditHours = 0;
    courseType = CourseType::Mandatory;
}

Course::Course(const std::string& courseCode,
               const std::string& courseName,
               int creditHours,
               CourseType courseType)
{
    this->courseCode = courseCode;
    this->courseName = courseName;
    this->creditHours = creditHours;
    this->courseType = courseType;
}


// Setters
void Course::setCourseCode(const std::string& courseCode)
{
    this->courseCode = courseCode;
}

void Course::setCourseName(const std::string& courseName)
{
    this->courseName = courseName;
}

void Course::setCreditHours(int creditHours)
{
    this->creditHours = creditHours;
}

void Course::setCourseType(CourseType courseType)
{
    this->courseType = courseType;
}


// Getters

std::string Course::getCourseCode() const
{
    return courseCode;
}

std::string Course::getCourseName() const
{
    return courseName;
}

int Course::getCreditHours() const
{
    return creditHours;
}

CourseType Course::getCourseType() const
{
    return courseType;
}
