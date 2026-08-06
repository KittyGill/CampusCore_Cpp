#include "Validation.h"

bool Validation::isValidId(int id)
{
    return id > 0;
}

bool Validation::isValidName(const std::string& name)
{
    return !name.empty();
}

bool Validation::isValidAge(int age)
{
    return age > 0 && age <= 100;
}

bool Validation::isValidBatch(const std::string& batch)
{
    return !batch.empty();
}

bool Validation::isValidSemester(int semester)
{
    return semester >= 1 && semester <= 8;
}

bool Validation::isValidCGPA(float cgpa)
{
    return cgpa >= 0.0f && cgpa <= 4.0f;
}