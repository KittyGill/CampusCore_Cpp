#pragma once

#include <string>
#include <vector>
#include "../models/Faculty.h"

class FacultyManager
{
private:
    std::vector<Faculty> faculties;

public:
    FacultyManager();

    bool addFaculty(const Faculty& faculty);

    void viewFaculties() const;

    Faculty* searchFaculty(const std::string& id);

    bool updateFaculty(const std::string& id, const Faculty& updatedFaculty);

    bool deleteFaculty(const std::string& id);

private:
    bool validateFaculty(const Faculty& faculty);    
};

