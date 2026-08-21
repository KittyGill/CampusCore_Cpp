#include "Validation.h"
#include <cctype>

//==========================
// Generic Validation
//==========================

bool Validation::isValidName(const std::string& name)
{
    return !name.empty();
}

bool Validation::isValidAge(int age)
{
    return age > 0 && age <= 100;
}

bool Validation::isValidSemester(int semester)
{
    return semester >= 1 && semester <= 8;
}

bool Validation::isValidCGPA(float cgpa)
{
    return cgpa >= 0.0f && cgpa <= 4.0f;
}

bool Validation::isValidBatch(const std::string& batch)
{
    return !batch.empty();
}

bool Validation::isValidCreditHours(int creditHours)
{
    return creditHours >= 1 && creditHours <= 3;
}

// =========================
// Student Validation
// =========================

bool Validation::isValidStudentID(const std::string& id)
{
    // Format: S001

    if (id.length() != 4)
        return false;

    if (id[0] != 'S')
        return false;

    for (int i = 1; i < 4; i++)
    {
        if (!isdigit(id[i]))
            return false;
    }

    return true;
}

// =========================
// Faculty Validation
// =========================

bool Validation::isValidFacultyID(const std::string& facultyID)
{
    if (facultyID.length() != 4)
        return false;

    if (facultyID[0] != 'F')
        return false;

    for (int i = 1; i < 4; i++)
    {
        if (!isdigit(facultyID[i]))
            return false;
    }

    return true;
}

bool Validation::isValidDepartment(const std::string& department)
{
    return !department.empty();
}

bool Validation::isValidJoiningDate(const std::string& joiningDate)
{
    // Format: YYYY-MM-DD
    if (joiningDate.length() != 10)
        return false;

    if (joiningDate[4] != '-' || joiningDate[7] != '-')
        return false;

    for (int i = 0; i < joiningDate.length(); i++)
    {
        if (i == 4 || i == 7)
            continue;

        if (!isdigit(joiningDate[i]))
            return false;
    }

    return true;
}

// =========================
// Course Validation
// =========================

bool Validation::isValidCourseCode(const std::string& id)
{
    if (id.length() != 5)
        return false;

    if (id[0] != 'C')
        return false;

    for (int i = 1; i < 5; i++)
    {
        if (!isdigit(id[i]))
            return false;
    }

    return true;
}

bool Validation::isValidCourseType(CourseType courseType)
{
    return courseType == CourseType::Mandatory || courseType == CourseType::Elective;
}

bool Validation::isValidPrerequisiteCourseCode(const std::string& prerequisiteCourseCode)
{
    // Prerequisite course code can be empty or a valid course code
    return prerequisiteCourseCode.empty() || isValidCourseCode(prerequisiteCourseCode);
}

bool Validation::isValidTuitionFee(int tuitionFee)
{
    return tuitionFee >= 15000 && tuitionFee <= 25000;
}

// =========================
// Course Slot Validation
// =========================

bool Validation::isValidCourseSlotCode(const std::string& courseSlotCode)
{
    if (courseSlotCode.length() != 5)
        return false;

    if (courseSlotCode[0] != 'C' || courseSlotCode[1] != 'S')
        return false;

    for (int i = 2; i < 5; i++)
    {
        if (!isdigit(courseSlotCode[i]))
            return false;
    }

    return true;
}

bool Validation::isValidDays(Days days)
{
    return days == Days::MonWed || days == Days::TueThu || days == Days::FriSat ||
           days == Days::MonWedFri || days == Days::TueThuSat;
}

bool Validation::isValidTime(Time time)
{
    return time == Time::Morning_0830_0930 || time == Time::Morning_0830_1000 ||
           time == Time::Noon_1200_1300 || time == Time::Noon_1200_1400 ||
           time == Time::Afternoon_1400_1500 || time == Time::Afternoon_1500_1600 ||
           time == Time::Evening_1600_1700 || time == Time::Evening_1700_1800;
}

bool Validation::isValidSeatsAvailable(int seatsAvailable)
{
    return seatsAvailable >= 0 && seatsAvailable <= 50;
}

bool Validation::isValidClassRoom(int classRoom)
{
    return classRoom >= 1 && classRoom <= 100;
}
