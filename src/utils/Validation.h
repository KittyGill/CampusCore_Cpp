#ifndef VALIDATION_H
#define VALIDATION_H

#include <string>

class Validation
{
public:
    //==========================
    // Generic Validation
    //==========================
    static bool isValidName(const std::string& name);
    static bool isValidAge(int age);

    //==========================
    // Student Validation
    //==========================
    static bool isValidStudentID(const std::string& id);
    static bool isValidSemester(int semester);
    static bool isValidCGPA(float cgpa);
    static bool isValidBatch(const std::string& batch);

    //==========================
    // Faculty Validation
    //==========================
    static bool isValidFacultyID(const std::string& id);
    static bool isValidDepartment(const std::string& department);
    static bool isValidJoiningDate(const std::string& joiningDate);

    //==========================
    // Course Validation
    //==========================
    static bool isValidCourseID(const std::string& id);
    static bool isValidCreditHours(int creditHours);

    //==========================
    // Course Slot Validation
    //==========================
    static bool isValidCourseSlotID(const std::string& id);
};

#endif