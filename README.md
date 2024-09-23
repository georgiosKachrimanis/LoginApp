
# User Management System (C++)

This project is a **User Management System** written in C++ that allows users to:
- **Sign Up** for an account with a username, password, and email.
- **Log In** using their registered credentials.
- **Recover their password** by verifying their email.
- Passwords are securely hashed using the **SHA-256** algorithm, and user data is stored in a text file (`loginData.txt`).

*Just FYI the most difficult part of this project was to make the Cryptopp library to work. If anyone has some tips how I can make it work 100%
when I install it in new computers I will be really grateful. My laptop is able to use the Crypto library, my normal pc not once!
You can contact me at georgios.kachrimanis@icloud.com*


## Features

- **User Registration**: Users can sign up by providing a unique username, a password (which is hashed using SHA-256), and a valid email address.
- **User Login**: Users can log in using their username and password. The system verifies the password by comparing the stored hash.
- **Password Recovery**: Users can recover their password by providing their username and registered email. A placeholder message for sending a password reset link is included.
- **Persistent File Storage**: User data is stored in a local file (`loginData.txt`), and the file is created automatically if it doesn't exist.

## Requirements

- **C++17 or higher**
- **Crypto++ library** for SHA-256 hashing
- **Microsoft Visual Studio** or any C++-compatible IDE

## Setup Instructions

### Step 1: Install the Crypto++ Library

To use the **SHA-256** hashing functionality, you need to install the **Crypto++** library.

1. Download **Crypto++** from the [official website](https://www.cryptopp.com/) or [GitHub repository](https://github.com/weidai11/cryptopp).
2. Extract the library files and set the **Include** directory and **Library** paths in your IDE.
3. In Visual Studio, right-click your project and go to **Properties**:
   - Under **VC++ Directories**, add the path to the **Crypto++** headers in **Include Directories**.
   - Under **Linker > Input**, add `cryptlib.lib` to **Additional Dependencies**.

### Step 2: Clone the Repository

Clone this repository to your local machine:

```bash
git clone https://github.com/georgiosKachrimanis/LoginApp.git
```

### Step 3: Build the Project

Open the project in **Visual Studio** or your preferred C++ IDE and build the project using the `Debug` or `Release` configuration.

## Usage

### 1. **Sign Up**

Users can sign up for a new account by entering a username, password, and email address. The system ensures the username is unique and stores the password as a SHA-256 hash.

### 2. **Log In**

Users can log in with their username and password. The system verifies the credentials by checking the SHA-256 hash stored in the `loginData.txt` file.

### 3. **Password Recovery**

If users forget their password, they can recover it by providing their username and registered email address. Currently, the system only displays a placeholder message that a reset link would be sent to their email.

## File Structure

```
|-- src/
|   |-- login.cpp       # Main entry point of the program
|   |-- user.cpp        # Implementation of the User class
|   |-- user.h          # Declaration of the User class
|-- loginData.txt       # File where user credentials are stored (auto-generated)
|-- README.md           # Project documentation
```

## Example

### 1. **Sign Up**

```
Enter a username: johndoe
Enter your password: ******
Please re-enter your password for confirmation: ******
Enter your email address: johndoe@example.com
User johndoe successfully registered!
```

### 2. **Log In**

```
Please enter your username: johndoe
Please enter your password: ******
Account Login Successful!
```

### 3. **Password Recovery**

```
Enter Your Username: johndoe
Enter your email address: johndoe@example.com
New Password reset link will be sent to the email: johndoe@example.com
```

## Future Enhancements

- **Email Integration**: Implement actual password reset functionality that sends an email to the user.
- **Encrypted File Storage**: Secure user data by encrypting the contents of the `loginData.txt` file.
- **Input Validation**: Improve input validation for more robust security and error handling.

## License

This project is open-source and available under the [MIT License](LICENSE).
