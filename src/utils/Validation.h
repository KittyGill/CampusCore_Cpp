#ifndef VALIDATION_H
#define VALIDATION_H

#include <string>

class Validation
{
public:
    static bool isValidId(int id);

    static bool isValidName(const std::string& name);

    static bool isValidAge(int age);

    static bool isValidBatch(const std::string& batch);

    static bool isValidSemester(int semester);

    static bool isValidCGPA(float cgpa);
};

#endif