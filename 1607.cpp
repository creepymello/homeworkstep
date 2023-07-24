#include <iostream>
#include <regex>

using namespace std;

class User {
private:
    string username;
    string password;

public:
    User(string username, string password){
        this->username = username;
        this->password = password;
    }

    string getUsername() const {
        return username;
    }

    bool checkPassword(string inputPassword) const {
        return password == inputPassword;
    }
};

class Log {
private:
    vector<User> users;

    bool isValidUsername(string username) const {
        regex usname("^[a-zA-Z0-9_-]{3,16}$");
        return regex_match(username, usname);
    }

    bool isValidPassword(string password) const {
        regex pass("^[a-zA-Z0-9@#%^&*()_+!]{6,50}$"); //тоже в инете чекнула, а то у меня мозг расплавиться пока пойму как днлать это
        return regex_match(password, pass);
    }

public:
    void registerUser() {
        string username, password;
        cout << "Enter your desired username: ";
        cin >> username;

        while (!isValidUsername(username)) {
            cout << "Invalid username. Username must contain 3-16 characters, consisting of letters, numbers, '_', or '-'." << endl;
            cout << "Enter your desired username: ";
            cin >> username;
        }

        cout << "Enter your desired password: ";
        cin >> password;

        while (!isValidPassword(password)) {
            cout << "Invalid password. Password must contain at least 6 characters, consisting of letters, numbers, or special characters like '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', or '+'." << endl;
            cout << "Enter your desired password: ";
            cin >> password;
        }

        users.push_back(User(username, password));
        cout << "Registration successful. You can now log in with your credentials." << endl;
    } // я точно не помню прошли ли мы push_back, но ребята сказали что прошли
    // не буду врать,чекнула это в инете:)

    User* loginUser() {
        string username, password;
        cout << "Enter your username: ";
        cin >> username;

        cout << "Enter your password: ";
        cin >> password;

        try {
            User& user = findUser(username);
            if (user.checkPassword(password)) {
                cout << "Login successful. Welcome, " << user.getUsername() << "!" << endl;
                return &user;
            } else {
                throw invalid_argument("Invalid password.");
            }
        } catch (const invalid_argument &e) {
            cout << "Login failed. " << e.what() << endl;
            return nullptr;
        }
    }

private:
    User& findUser(string username) {
        for (size_t i = 0; i < users.size(); ++i) {
            if (users[i].getUsername() == username) {
                return users[i];
            }
        }
        throw invalid_argument("User not found.");
    }
};

int main() {
    Log regis;

    while (true) {
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                regis.registerUser();
                break;
            case 2: {
                User *user = regis.loginUser();
                break;
            }
            case 3:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
