#ifndef USER_H
#define USER_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <iomanip>
#include <cryptopp/sha.h>
#include <cryptopp/filters.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>




using namespace std;

class User {
	private:
		int userID;
		string userName;
		string userEmail;
		string userPassword;
		fstream file;
	public:
		User();
		User(string uName, string mail, string pwd);

		void login();
		void signUp();
		void passswordRecovery();

		string getUserName()const;
		string getUserPassword()const;
		string getUserEmail()const;

		string getValidatedUsername();
		string getValidatedPassword();
		bool findUser(const string& username, const string& password = "");
		string getValidatedEmail();

		// File operations later on can be seperated to a different class if need it be.
		bool openFileForReading();
		bool openFileForWriting();
		bool appendUserToFile(const User& user);

};

#endif // !USER_H

