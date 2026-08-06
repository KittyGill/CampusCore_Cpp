#pragma once

#include <vector>
#include "../models/Student.h"

class StudentManager
{
private:
    std::vector<Student> students;

public:
    StudentManager();

    void addStudent(const Student& student);

    void viewStudents() const;

    Student* searchStudent(const std::string& id);

    bool updateStudent(const std::string& id, const Student& updatedStudent);

    bool deleteStudent(const std::string& id);
};