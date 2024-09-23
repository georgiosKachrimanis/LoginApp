#ifndef USER_H
#define USER_H

#include <iostream>
#include <fstream>
#include <string>
#include <optional>

class User {
private:
    int userID;
    std::string userName;
    std::string userEmail;
    std::string userPassword;
    std::fstream file;
public:
    User();
    User(std::string uName, std::string mail, std::string pwd);

    void login();
    void signUp();
    void passswordRecovery();

    std::string getUserName() const;
    std::string getUserPassword() const;
    std::string getUserEmail() const;

    std::string getValidatedUsername();
    std::string getValidatedPassword();
    std::optional<User> findUser(const std::string& username, const std::string& password = "");
    std::string getValidatedEmail();

    // File operations
    void initializeLoginFile();
    bool openFileForReading();
    bool openFileForWriting();
    bool appendUserToFile(const User& user);
};

#endif  // USER_H
