#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "user.h"

using namespace std;


int main()
{
	
	char choice;

	User user;

	cout << "\n1 - Login ";
	cout << "\n2 - Sign Up ";
	cout << "\n3 - Forgot Password ";
	cout << "\n4 - Exit ";
	cout << "\nPlease enter your choice " << endl;
	cin >> choice;

	switch (choice)
	{
	case '1':
		
		break;
	case '2':
		cin.get();
		user.signUp();
		break;
	case '3':
		break;
	case '4':
		break;
	default:
		cout << "Invalid choice!\n Try again!";
		
	}
}