#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>

enum class CourseType
{
    Mandatory,
    Elective
};

class Course
{
private:
    std::string courseCode;
    std::string courseName;
    int creditHours;
    CourseType courseType;
public:
    // Constructors
    Course();
    Course(const std::string& courseCode,
            const std::string& courseName,
            int creditHours,
            CourseType courseType);

    // Getters
    std::string getCourseCode() const;
    std::string getCourseName() const;
    int getCreditHours() const;
    CourseType getCourseType() const;

    // Setters
    void setCourseCode(const std::string& courseCode);
    void setCourseName(const std::string& courseName);
    void setCreditHours(int creditHours);
    void setCourseType(CourseType courseType);

    // Display
    void displayCourse() const;
};

#endif