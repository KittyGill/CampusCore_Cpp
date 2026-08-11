#ifndef COURSESLOT_H
#define COURSESLOT_H

#include <string>

class Course
{
private:
    std::string courseCode;
    std::string name;
    int creditHours;
    std::string prerequisiteCourseCode;
    int tuitionFee;

public:
    // Constructors
    Course();
    Course(const std::string& courseCode,
        const std::string& name,
        int creditHours,
        CourseType courseType,
        const std::string& prerequisiteCourseCode,
        int tuitionFee);

    // Getters
    std::string getCourseCode() const;
    std::string getName() const;
    int getCreditHours() const;
    CourseType getCourseType() const;
    std::string getPrerequisiteCourseCode() const;
    int getTuitionFee() const;

    // Setters
    void setCourseCode(const std::string& courseCode);
    void setName(const std::string& name);
    void setCreditHours(int creditHours);
    void setCourseType(CourseType courseType);
    void setPrerequisiteCourseCode(const std::string& prerequisiteCourseCode);
    void setTuitionFee(int tuitionFee);

    // Display
    void displayCourse() const;
};

#endif