#include "user.h"
#include <regex>
#include <cryptopp/sha.h>
#include <cryptopp/filters.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>

using namespace std;

using namespace CryptoPP;

string sha256(const string& input) {

	SHA256 hash;

	string digest;

	StringSource(input, true,
		new HashFilter(hash,
			new HexEncoder(
				new StringSink(digest))));

	return digest;
}

User::User()
{
	userName = "";
	userEmail = "";
	userPassword = "";
}

User::User(string userName, string email, string pwd)
{
	this->userName = userName;
	this->userEmail = email;
	this->userPassword = pwd;
}

void User::login() {
	string userLoginName;
	string userLoginPwd;

	cout << " <----------- Login Page -----------------> " << endl;
	cout << "Please enter your username: ";
	getline(cin, userLoginName);
	cout << "\nPlease enter your password: ";
	getline(cin, userLoginPwd);

	// convert user password input to sha256
	userLoginPwd = sha256(userLoginPwd);

	// Check if the username and password match
	if (findUser(userLoginName, userLoginPwd)) {
		cout << "\nAccount Login Successful...!" << endl;
	}
	else {
		cout << "Invalid username or password." << endl;
	}
}


void User::signUp()
{
	string tempName;
	string tempEmail;
	string tempPassword;

	tempName = getValidatedUsername();
	tempPassword = getValidatedPassword();
	tempEmail = getValidatedEmail();


	if (!tempName.empty() && !tempPassword.empty() && !tempEmail.empty())
	{
		if (!findUser(tempName).has_value()) {
			User newUser(tempName, tempEmail, sha256(tempPassword));

			if (appendUserToFile(newUser))
			{
				cout << "User " << newUser.getUserName() << " successfully registered!\n";
			}
			else
			{
				cout << "Failed attempt, please try again." << endl;
			}
		}
	}
	else
	{
		cout << "Please try again, all fields need to be filled!" << endl;
	}
}

void User::passswordRecovery()
{
	string searchName, searchEmail;

	cout << "\nEnter Your UserName : ";
	getline(cin, searchName);
	searchEmail = getValidatedEmail();

	optional<User> user = findUser(searchName);

	if (user.has_value() && user->getUserEmail() == searchEmail)
	{
		cout << "New Password reset link will be send to the email: " << searchEmail;
	}
	else
	{
		cout << "Invalid username or email. Please try again! " << endl;
	}

}

string User::getUserName() const
{
	return userName;
}

string User::getUserPassword() const
{
	return userPassword;
}

string User::getUserEmail() const
{
	return userEmail;
}

optional<User> User::findUser(const string& username, const string& password) {
	string userName, email, storedPassword;

	// Open the file for reading
	if (openFileForReading()) {
		while (getline(file, userName, '*') && getline(file, email, '*') && getline(file, storedPassword)) {
			if (userName == username) {
				// If password is provided, check if it matches (login function)
				if (!password.empty()) {
					if (storedPassword == password) {
						file.close();
						// Return a User object with the found data
						return User(userName, email, storedPassword);
					}
					else {
						file.close();
						return std::nullopt;  // Password mismatch
					}
				}
				else {
					// If no password is provided, return user data for further processing (e.g., password recovery)
					file.close();
					return User(userName, email, storedPassword);
				}
			}
		}
	}

	file.close();
	return std::nullopt;  // Username not found
}


string User::getValidatedUsername() {
	string tempName;
	cout << "Enter a username: ";
	getline(cin, tempName);

	while (findUser(tempName)) {
		cout << "Username is already taken. Please choose a different username.\n";
		getline(cin, tempName);
	}

	return tempName;
}

string User::getValidatedPassword() {
	string tempPassword1, tempPassword2;
	cout << "Enter your password: ";
	getline(cin, tempPassword1);
	cout << "Please re-enter your password for confirmation: ";
	getline(cin, tempPassword2);

	while (tempPassword1 != tempPassword2) {
		cout << "The passwords do not match. Please enter the confirmation password again." << endl;
		getline(cin, tempPassword2);
	}

	return tempPassword1;
}

string User::getValidatedEmail() {
	const regex pattern("[\\w\\.-]+@[\\w\\.-]+\\.[a-zA-Z]{2,}");
	string tempEmail;

	cout << "Enter your email address: ";
	getline(cin, tempEmail);

	while (!regex_match(tempEmail, pattern))
	{
		cout << "The email is not valid. Please try again. \n";
		getline(cin, tempEmail);
	}

	return tempEmail;
}

// File operations

bool User::openFileForReading() {
	file.open("loginData.txt", ios::in);
	if (!file.is_open()) {
		cout << "Error: Could not open the login data file." << endl;
		return false;
	}
	return true;
}

bool User::openFileForWriting() {
	file.open("loginData.txt", ios::out | ios::app);
	if (!file.is_open()) {
		cout << "Error: Could not open the login data file for writing." << endl;
		return false;
	}
	return true;
}

bool User::appendUserToFile(const User& user) {
	if (openFileForWriting()) {
		file << user.getUserName() << "*" << user.getUserEmail() << "*" << user.getUserPassword() << endl;
		file.close();
		return true;
	}
	return false;
}

void User::initializeLoginFile() {
	ifstream file("loginData.txt");

	// If file doesn't exist or couldn't be opened, create it
	if (!file.is_open()) {
		ofstream outfile("loginData.txt");  // Create the file
		if (!outfile) {
			cout << "Error: Could not create loginData.txt."
				<< "\nPlease close the app and try again!."
				<< "\nIf the problem consists please contact the customer support" << endl;
		}
		outfile.close();
	}
	else {
		file.close();  // Close if it already exists
	}
}



