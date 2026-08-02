#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include <vector>

class Admin
{
private:
    int id;
    std::string username;
    std::string password;
    std::string name;

public:
    // Constructors
    Admin();
    Admin(int id,
        const std::string& username,
        const std::string& password,
        const std::string& name);

    // Getters
    int getId() const;
    std::string getUsername() const;
    std::string getPassword() const;
    std::string getName() const;

    // Setters
    void setId(int id);
    void setUsername(const std::string& username);
    void setPassword(const std::string& password);
    void setName(const std::string& name);

};

#endif