#include <iostream>
#include <string>
#include "user.h"

using namespace std;

void clearScreen();
void displayMenu();
void runMenu(User & user);
void pauseScreen();

int main()
{	
	User user;
	runMenu(user);

	return 0;
}

void runMenu(User & user)
{
	char choice;

	do {

		displayMenu();
		cin >> choice;

		switch (choice)
		{
		case '1':
			cin.get();
			user.login();
			pauseScreen();
			break;
		case '2':
			cin.get();
			user.signUp();
			pauseScreen();
			break;
		case '3':
			cin.get();
			user.passswordRecovery();
			pauseScreen();
			break;
		case '4':
			cout << "Thank you for using our application.\nSee you again next time. " << endl;
			break;
		default:
			cout << "Invalid choice!\n Try again!";
			pauseScreen();
		}
	} while (choice != '4');

}

void displayMenu() 
{
	clearScreen();

	cout << "\n1 - Login ";
	cout << "\n2 - Sign Up ";
	cout << "\n3 - Forgot Password ";
	cout << "\n4 - Exit ";
	cout << "\nPlease enter your choice " << endl;
}

void clearScreen() {
#ifdef _WIN32
	system("cls");  // For Windows
#else
	system("clear");  // For Linux/macOS
#endif
}

void pauseScreen() {
	cout << "\nPress Enter to continue...";
	cin.ignore();
	cin.get();
}
