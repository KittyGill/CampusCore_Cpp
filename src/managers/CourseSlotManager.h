#pragma once

#include <vector>
#include "../models/CourseSlot.h"

class CourseSlotManager
{
private:
    std::vector<CourseSlot> courseSlots;

public:
    CourseSlotManager();

    bool addCourseSlot(const CourseSlot& courseSlot);

    void viewCourseSlots() const;

    CourseSlot* searchCourseSlot(const std::string& courseSlotCode);

    bool updateCourseSlot(const std::string& courseSlotCode,
                          const CourseSlot& updatedCourseSlot);

    bool deleteCourseSlot(const std::string& courseSlotCode);

private:
    bool validateCourseSlot(const CourseSlot& courseSlot);
};