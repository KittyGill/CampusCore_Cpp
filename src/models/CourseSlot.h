#pragma once

#include <string>

// =========================
// Course Slot Days
// =========================
enum class Days
{
    MonWed,
    TueThu,
    FriSat,
    MonWedFri,
    TueThuSat
};

// =========================
// Course Slot Time
// =========================
enum class Time
{
    Morning_0830_0930,
    Morning_0830_1000,
    Noon_1200_1300,
    Noon_1200_1400,
    Afternoon_1400_1500,
    Afternoon_1500_1600,
    Evening_1600_1700,
    Evening_1700_1800
};

class CourseSlot
{
private:
    std::string courseSlotCode;      // CS001
    std::string courseCode;          // C001

    Days days;
    Time time;
    
    int classRoom;
    int seatsAvailable;

    std::string facultyID;           // F001 (optional for now)

public:
    // Constructors
    CourseSlot();

    CourseSlot(const std::string& courseSlotCode,
               const std::string& courseCode,
               Days days,
               Time time,
               int classRoom,
               int seatsAvailable,
               const std::string& facultyID = "");

    // Getters
    std::string getCourseSlotCode() const;
    std::string getCourseCode() const;
    Days getDays() const;
    Time getTime() const;
    int getClassRoom() const;
    int getSeatsAvailable() const;
    std::string getFacultyID() const;

    // Setters
    void setCourseSlotCode(const std::string& courseSlotCode);
    void setCourseCode(const std::string& courseCode);
    void setDays(Days days);
    void setTime(Time time);
    void setClassRoom(int classRoom);
    void setSeatsAvailable(int seatsAvailable);
    void setFacultyID(const std::string& facultyID);

    // Display
    void displayCourseSlot() const;
};