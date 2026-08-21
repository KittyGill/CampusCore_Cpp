#include <iostream>
#include "CourseSlotManager.h"
#include "../utils/Validation.h"

CourseSlotManager::CourseSlotManager()
{

}

bool CourseSlotManager::addCourseSlot(const CourseSlot& courseSlot)
{
    if (!validateCourseSlot(courseSlot))
    {   
        std::cout << "validateCourse() called\n"; 
        return false;
    }
    courseSlots.push_back(courseSlot);

    std::cout << "Course slot added!" << std::endl;
    std::cout << "Total course slots: " << courseSlots.size() << std::endl;
    return true;
}

void CourseSlotManager::viewCourseSlots() const
{
    std::cout << "Inside viewCourseSlots()" << std::endl;

    for (const CourseSlot& slot : courseSlots)
    {
        slot.displayCourseSlot();
    }
}

CourseSlot* CourseSlotManager::searchCourseSlot(const std::string& code)
{
    for (const CourseSlot& slot : courseSlots)
    {
        if (slot.getCourseCode() == code)
        {
            return const_cast<CourseSlot*>(&slot);
        }
    }

    return nullptr;
}

bool CourseSlotManager::updateCourseSlot(const std::string& id, const CourseSlot& updatedCourseSlot)
{
    CourseSlot* courseSlot = searchCourseSlot(id);

    if (courseSlot != nullptr)
    {
        *courseSlot = updatedCourseSlot;
        return true;
    }

    return false;
}

bool CourseSlotManager::deleteCourseSlot(const std::string& id)
{
    for (auto it = courseSlots.begin(); it != courseSlots.end(); ++it)
    {
        if (it->getCourseSlotCode() == id)
        {
            courseSlots.erase(it);
            return true;
        }
    }

    return false;
}

// Validation function to check if the course data is valid
bool CourseSlotManager::validateCourseSlot(const CourseSlot& courseSlot)
{
    if (!Validation::isValidCourseSlotCode(courseSlot.getCourseSlotCode()))
    {
        std::cout << "Invalid course slot code: " << courseSlot.getCourseSlotCode() << std::endl;
        return false;
    }

    if (!Validation::isValidDays(courseSlot.getDays()))
    {
        std::cout << "Invalid Days: " << static_cast<int>(courseSlot.getDays()) << std::endl;
        return false;
    }

    if (!Validation::isValidTime(courseSlot.getTime()))
    {
        std::cout << "Invalid course slot time: " << static_cast<int>(courseSlot.getTime()) << std::endl;
        return false;
    }

    if (!Validation::isValidSeatsAvailable(courseSlot.getSeatsAvailable()))
    {
        std::cout << "Invalid seats available: " << courseSlot.getSeatsAvailable() << std::endl;
        return false;
    }

    if (!Validation::isValidClassRoom(courseSlot.getClassRoom()))
    {
        std::cout << "Invalid class room: " << courseSlot.getClassRoom() << std::endl;
        return false;
    }

    if (!Validation::isValidFacultyID(courseSlot.getFacultyID()))
    {
        std::cout << "Invalid Faculty ID: " << courseSlot.getFacultyID() << std::endl;
    }

    return true;
}