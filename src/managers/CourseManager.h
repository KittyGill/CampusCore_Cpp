#pragma once

#include <string>
#include <vector>
#include "../models/Course.h"

class CourseManager
{
private:
    std::vector<Course> courses;

public:
    CourseManager();

    bool addCourse(const Course& course);

    void viewCourses() const;

    Course* searchCourse(const std::string& code);

    bool updateCourse(const std::string& code, const Course& updatedCourse);

    bool deleteCourse(const std::string& code);

private:
    bool validateCourse(const Course& course);    
};

