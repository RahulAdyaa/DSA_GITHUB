// TC: O(d), SC: O(1)
// Where d = number of digits in the number `num`

#include <iostream>
#include <string>
using namespace std;

int maximum69Number(int num) {
    // Convert integer to string for easy digit manipulation
    string s = to_string(num);

    // Traverse the digits to find the first '6' and change it to '9'
    for (char &c : s) {
        if (c == '6') {
            c = '9';  // Change the first '6' to '9'
            break;    // Only change one digit
        }
    }

    // Convert string back to integer and return
    return stoi(s);
}

int main() {
    int num = 666669;
    int result = maximum69Number(num);
    cout << "Maximum number after changing at most one 6 to 9: " << result << endl;
    return 0;
}
