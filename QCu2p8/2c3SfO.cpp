#include <iostream>
using namespace std;
#include <regex>

bool isValidEmail(const string& email) {
    // Regular expression pattern for a basic email validation
    const regex pattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,4})");

    return regex_match(email, pattern);
}

int main() {
    string email;
    cout << "Enter an email address: ";
    cin >> email;

    if (isValidEmail(email)) {
      cout << "Valid email address." <<endl;
    } else {
        cout << "Invalid email address." << endl;
    }

    return 0;
}
