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

    Student* searchStudent(int id);

    bool updateStudent(int id, const Student& updatedStudent);

    bool deleteStudent(int id);
};