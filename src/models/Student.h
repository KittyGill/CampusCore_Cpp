#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

class Student
{
private:
    int id;
    std::string name;
    int age;
    std::string batch;
    int currentSemester;
    float cgpa;
    std::vector<std::string> registeredCourses;

public:
    // Constructors
    Student();
    Student(int id,
            std::string name,
            int age,
            std::string batch,
            int currentSemester,
            float cgpa);

    // Getters
    int getId() const;
    std::string getName() const;
    int getAge() const;
    std::string getBatch() const;
    int getCurrentSemester() const;
    float getCGPA() const;
    const std::vector<std::string> getRegisteredCourses() const;

    // Setters
    void setId(int id);
    void setName(const std::string& name);
    void setAge(int age);
    void setBatch( const std::string& batch);
    void setCurrentSemester(int semester);
    void setCGPA(float cgpa);

    // Course Functions
    void registerCourse(std::string courseCode);
    void removeCourse(std::string courseCode);

    // Display
    void displayStudent() const;
};

#endif