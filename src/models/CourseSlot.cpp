#include "CourseSlot.h"
#include <iostream>

CourseSlot::CourseSlot()
{
    courseSlotCode = "";
    courseCode = "";
    days = Days::MonWed;
    time = Time::Morning_0830_0930;
    classRoom = 0;
    seatsAvailable = 0;
    facultyID = "";
}

CourseSlot::CourseSlot(const std::string& courseSlotCode,
                       const std::string& courseCode,
                       Days days,
                       Time time,
                       int classRoom,
                       int seatsAvailable,
                       const std::string& facultyID)
{
    this->courseSlotCode = courseSlotCode;
    this->courseCode = courseCode;
    this->days = days;
    this->time = time;
    this->classRoom = classRoom;
    this->seatsAvailable = seatsAvailable;
    this->facultyID = facultyID;
}

// Setters
void CourseSlot::setCourseSlotCode(const std::string& courseSlotCode)
{
    this->courseSlotCode = courseSlotCode;
}

void CourseSlot::setCourseCode(const std::string& courseCode)
{
    this->courseCode = courseCode;
}

void CourseSlot::setDays(Days days)
{
    this->days = days;
}

void CourseSlot::setTime(Time time)
{
    this->time = time;
}

void CourseSlot::setClassRoom(int classRoom)
{
    this->classRoom = classRoom;
}

void CourseSlot::setSeatsAvailable(int seatsAvailable)
{
    this->seatsAvailable = seatsAvailable;
}

void CourseSlot::setFacultyID(const std::string& facultyID)
{
    this->facultyID = facultyID;
}
    
// Getters

std::string CourseSlot::getCourseSlotCode() const
{
    return courseSlotCode;
}

std::string CourseSlot::getCourseCode() const
{
    return courseCode;
}

Days CourseSlot::getDays() const
{
    return days;
}

Time CourseSlot::getTime() const
{
    return time;
}


int CourseSlot::getSeatsAvailable() const
{
    return seatsAvailable;
}

int CourseSlot::getClassRoom() const
{
    return classRoom;
}

std::string CourseSlot::getFacultyID() const
{
    return facultyID;
}

void CourseSlot::displayCourseSlot() const
{
    std::cout << "Inside displayCourseSlots()" << std::endl;

    std::cout << "Course Slot Code: " << courseSlotCode << std::endl;
    std::cout << "Course Code: " << courseCode << std::endl;
    std::cout << "Days: " << static_cast<int>(days) << std::endl;
    std::cout << "Time: " << static_cast<int>(time) << std::endl;
    std::cout << "Class Room: " << classRoom << std::endl;
    std::cout << "Seats Available: " << seatsAvailable << std::endl;
    std::cout << "------------------------" << std::endl;
}
