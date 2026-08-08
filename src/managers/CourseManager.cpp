#include <iostream>
#include "CourseManager.h"
#include "../utils/Validation.h"

CourseManager::CourseManager()
{

}

bool CourseManager::addCourse(const Course& course)
{
    if (!validateCourse(course))
    {   
        std::cout << "validateCourse() called\n"; 
        return false;
    }
    courses.push_back(course);

    std::cout << "Course added!" << std::endl;
    std::cout << "Total courses: " << courses.size() << std::endl;
    return true;
}

void CourseManager::viewCourses() const
{
    std::cout << "Inside viewCourses()" << std::endl;

    for (const Course& course : courses)
    {
        course.displayCourse();
    }
}

Course* CourseManager::searchCourse(const std::string& code)
{
    for (const Course& course : courses)
    {
        if (course.getCourseCode() == code)
        {
            return const_cast<Course*>(&course);
        }
    }

    return nullptr;
}

bool CourseManager::updateCourse(const std::string& id, const Course& updatedCourse)
{
    Course* course = searchCourse(id);

    if (course != nullptr)
    {
        *course = updatedCourse;
        return true;
    }

    return false;
}

bool CourseManager::deleteCourse(const std::string& id)
{
    for (auto it = courses.begin(); it != courses.end(); ++it)
    {
        if (it->getCourseCode() == id)
        {
            courses.erase(it);
            return true;
        }
    }

    return false;
}

// Validation function to check if the course data is valid
bool CourseManager::validateCourse(const Course& course)
{
    if (!Validation::isValidCourseCode(course.getCourseCode()))
    {
        std::cout << "Invalid course code: " << course.getCourseCode() << std::endl;
        return false;
    }

    if (!Validation::isValidName(course.getName()))
    {
        std::cout << "Invalid course name: " << course.getName() << std::endl;
        return false;
    }

    if (!Validation::isValidCreditHours(course.getCreditHours()))
    {
        std::cout << "Invalid course credit hours: " << course.getCreditHours() << std::endl;
        return false;
    }

    if (!Validation::isValidCourseType(course.getCourseType()))
    {
        std::cout << "Invalid course type: " << static_cast<int>(course.getCourseType()) << std::endl;
        return false;
    }

    if (!Validation::isValidPrerequisiteCourseCode(course.getPrerequisiteCourseCode()))
    {
        std::cout << "Invalid prerequisite course code: " << course.getPrerequisiteCourseCode() << std::endl;
        return false;
    }

    if (!Validation::isValidTuitionFee(course.getTuitionFee()))
    {
        std::cout << "Invalid Tuition Fees: " << course.getTuitionFee() << std::endl;
    }

    return true;
}