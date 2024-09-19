# User Management System (C++)

*WIP*

This project is a **User Management System** implemented in C++ that allows users to sign up, log in, and manage their credentials. The system uses file-based storage (`loginData.txt`) to save user credentials, and passwords are securely hashed using the **SHA-256** algorithm from the Crypto++ library.

## Features

- **User Registration**: Users can create an account by providing a username, password, and email.
- **User Login**: Registered users can log in by providing a username and password.
- **Password Hashing**: Passwords are hashed using **SHA-256** for secure storage.
- **Email Validation**: Basic email validation is performed using regular expressions.
- **File-based Storage**: User data is stored in a file (`loginData.txt`), which is used for login and signup operations.

## Requirements

- **C++17 or higher**
- **Crypto++** (Crypto++ library is required for SHA-256 hashing)
- **Microsoft Visual Studio** (or any other C++ IDE)

## Installation

### Setting up Crypto++ for Visual Studio

1. Download and install the **Crypto++** library from the [Crypto++ GitHub repository](https://github.com/weidai11/cryptopp).
2. Extract the library files and add the include directory to your project:
   - In Visual Studio, right-click your project and go to **Properties**.
   - Under **VC++ Directories**, add the path to the **Crypto++** headers in **Include Directories**.
3. Link the library:
   - Under **Linker > Input**, add `cryptlib.lib` to **Additional Dependencies**.

### Clone the Repository

1. Clone this repository to your local machine:

    ```bash
    git clone https://github.com/georgiosKachrimanis/LoginApp.git
    ```

2. Open the project in Visual Studio.

3. Build the project using the `Debug` or `Release` configuration.

## Usage

### 1. **Sign Up**
   - Users can sign up by entering a username, password, and email.
   - Passwords are securely hashed and stored in `loginData.txt`.
   
### 2. **Log In**
   - Users can log in by providing their username and password.
   - The system checks the username and compares the hashed password with the stored hash.

### 3. **Password Recovery (Optional)**
   - A placeholder function exists for future implementation of password recovery.

## File Structure

```
|-- src/
|   |-- user.cpp        # Implementation of User class
|   |-- user.h          # Declaration of User class
|-- loginData.txt       # File where user credentials are stored (auto-generated)
|-- README.md           # Project documentation
```

## Example

1. **Sign Up**
    ```
    Enter a username: johndoe
    Enter your password (input will be hidden): ******
    Please re-enter your password for confirmation: ******
    Enter your email address: johndoe@example.com
    User johndoe successfully registered!
    ```

2. **Login**
    ```
    Please enter your username: johndoe
    Please enter your password: ******
    Account Login Successful!
    ```

## Future Enhancements

- **Password Recovery**: Implement password recovery functionality.
- **Encrypted File Storage**: Encrypt user data for additional security.
- **Error Logging**: Implement error logging for debugging and maintenance.

## License

This project is open-source and available under the [MIT License](LICENSE).


