#include "Admin.h"

Admin::Admin()
{
    id = 0;
    username = "";
    password = "";
    name = "";
}

Admin::Admin(int id,
             const std::string& username,
             const std::string& password,
             const std::string& name)
{
    this->id = id;
    this->username = username;
    this->password = password;
    this->name = name;
}

// Setters
void Admin::setId(int id)
{
    this->id = id;
}

void Admin::setUsername(const std::string& username)
{
    this->username = username;
}

void Admin::setPassword(const std::string& password)
{
    this->password = password;
}

void Admin::setName(const std::string& name)
{
    this->name = name;
}

// Getters

int Admin::getId() const
{
    return id;
}

std::string Admin::getUsername() const
{
    return username;
}

std::string Admin::getPassword() const
{
    return password;
}

std::string Admin::getName() const
{
    return name;
}
