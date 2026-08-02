#ifndef FACULTY_H
#define FACULTY_H

#include <string>
#include <vector>

class Faculty
{
private:
    int id;
    std::string name;
    int age;
    std::string department;
    std::string joiningDate;
    std::vector<std::string> coursesTeaching;

public:
    // Constructors
    Faculty();
    Faculty(int id,
        const std::string& name,
        int age,
        const std::string& department,
        const std::string& joiningDate);

    // Getters
    int getId() const;
    std::string getName() const;
    int getAge() const;
    std::string getDepartment() const;
    std::string getJoiningDate() const;
    const std::vector<std::string> getCoursesTeaching() const;

    // Setters
    void setId(int id);
    void setName(const std::string& name);
    void setAge(int age);
    void setDepartment(const std::string& department);
    void setJoiningDate(const std::string& joiningDate);

    // Course Functions
    void assignCourse(std::string courseCode);
    void removeCourse(std::string courseCode);

    // Display
    void displayFaculty() const;
};

#endif