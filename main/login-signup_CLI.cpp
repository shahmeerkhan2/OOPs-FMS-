#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

class Signup {
private:
    string username;
    string password;
    string email;

    bool is_valid(string p) {
        if (p.length() < 8) { 
            cout << "Error: Password must be at least 8 chars\n"; 
            return false;
        }
        if (!any_of(p.begin(), p.end(), ::isupper)) { 
            cout << "Error: Must have uppercase\n"; 
            return false;
        }
        if (!any_of(p.begin(), p.end(), ::islower)) { 
            cout << "Error: Must have lowercase\n"; 
            return false;
        }
        if (!any_of(p.begin(), p.end(), ::isdigit)) { 
            cout << "Error: Must have digit\n"; 
            return false;
        }
        return true;
    }

public:
    void sign_up() {
        string u, p, e;
        cout << "Enter username: ";
        cin >> u;

        // Make sure the username is unique
        ifstream infile("users.txt");
        string checkU, checkP, checkE;
        while (infile >> checkU >> checkP >> checkE) {
            if (checkU == u) {
                cout << "Error: Username already exists!\n";
                infile.close();
                return; // stop signup
            }
        }
        infile.close();

        // Enter a valid password
        do {
            cout << "Enter password: ";
            cin >> p;
        } while (!is_valid(p));

        cout << "Enter email: ";
        cin >> e;

        ofstream file("users.txt", ios::app);
        file << u << " " << p << " " << e << endl;
        file.close();

        cout << "\nSignup successful!" << endl;
    }
};
bool authenticate(string inputU, string inputP) {
    ifstream file("users.txt");
    string u, p, e;

    while (file >> u >> p >> e) {
        if (inputU == u && inputP == p) {
            file.close();
            return true; // user found
        }
    }

    file.close();
    return false; // user not found
}


class login {
    public:
    bool authenticate(string inputU, string inputP) {
    ifstream file("users.txt");
    string u, p, e;

    while (file >> u >> p >> e) {
        if (inputU == u && inputP == p) {
            file.close();
            return true; // user found
        }
    }

    file.close();
    return false; // user not found
}
    void login_user() {
        string u, p;
        cout << "Enter username: ";
        cin >> u;
        cout << "Enter password: ";
        cin >> p;

        if (authenticate(u, p)) {
            cout << "Login successful!\n";
        } else {
            cout << "Error: Wrong username or password!\n";
        }
    }  
};
// Main program
int main() {
    int choice;
    cout << "1. Signup\n2. Login\nChoice: ";
    cin >> choice;

    if (choice == 1) {
        Signup s;
        s.sign_up();
    } 
    else if (choice == 2) {
        login l;
        l.login_user();
        
}
    else {
        cout << "Invalid choice!\n";
    }

    return 0;
}