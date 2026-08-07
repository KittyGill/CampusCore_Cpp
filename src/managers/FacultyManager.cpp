#include <iostream>
#include "FacultyManager.h"
#include "../utils/Validation.h"

FacultyManager::FacultyManager()
{

}

bool FacultyManager::addFaculty(const Faculty& faculty)
{
    if (!validateFaculty(faculty))
    {   
        std::cout << "validateFaculty() called\n"; 
        return false;
    }
    faculties.push_back(faculty);

    std::cout << "Faculty added!" << std::endl;
    std::cout << "Total faculties: " << faculties.size() << std::endl;
    return true;
}

void FacultyManager::viewFaculties() const
{
    std::cout << "Inside viewFaculties()" << std::endl;

    for (const Faculty& faculty : faculties)
    {
        faculty.displayFaculty();
    }
}

Faculty* FacultyManager::searchFaculty(const std::string& id)
{
    for (const Faculty& faculty : faculties)
    {
        if (faculty.getId() == id)
        {
            return const_cast<Faculty*>(&faculty);
        }
    }

    return nullptr;
}

bool FacultyManager::updateFaculty(const std::string& id, const Faculty& updatedFaculty)
{
    Faculty* faculty = searchFaculty(id);

    if (faculty != nullptr)
    {
        *faculty = updatedFaculty;
        return true;
    }

    return false;
}

bool FacultyManager::deleteFaculty(const std::string& id)
{
    for (auto it = faculties.begin(); it != faculties.end(); ++it)
    {
        if (it->getId() == id)
        {
            faculties.erase(it);
            return true;
        }
    }

    return false;
}

// Validation function to check if the faculty data is valid
bool FacultyManager::validateFaculty(const Faculty& faculty)
{
    if (!Validation::isValidFacultyID(faculty.getId()))
    {
        std::cout << "Invalid faculty ID: " << faculty.getId() << std::endl;
        return false;
    }

    if (!Validation::isValidName(faculty.getName()))
    {
        std::cout << "Invalid faculty name: " << faculty.getName() << std::endl;
        return false;
    }

    if (!Validation::isValidAge(faculty.getAge()))
    {
        std::cout << "Invalid faculty age: " << faculty.getAge() << std::endl;
        return false;
    }

    if (!Validation::isValidDepartment(faculty.getDepartment()))
    {
        std::cout << "Invalid faculty department: " << faculty.getDepartment() << std::endl;
        return false;
    }

    if (!Validation::isValidJoiningDate(faculty.getJoiningDate()))
    {
        std::cout << "Invalid faculty joining date: " << faculty.getJoiningDate() << std::endl;
        return false;
    }


    if (!Validation::isValidName(faculty.getName()))
        return false;

    if (!Validation::isValidAge(faculty.getAge()))
        return false;

    if (!Validation::isValidDepartment(faculty.getDepartment()))
        return false;

    if (!Validation::isValidJoiningDate(faculty.getJoiningDate()))
        return false;

    return true;
}