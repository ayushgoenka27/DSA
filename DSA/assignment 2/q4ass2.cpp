#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string concat(string st1, string st2) {
    st1.append(st2);
    return st1;
}
string reverse_str(string st1) {
    reverse(st1.begin(), st1.end());
    return st1;
}
string delVowels(string s) {
    string result = ""; 
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u' &&
            ch != 'A' && ch != 'E' && ch != 'I' && ch != 'O' && ch != 'U') {
            result += ch;  
        }
    }
    return result;
}
string sort_str(string st1) {
    sort(st1.begin(), st1.end());
    return st1;
}
char upp_to_low(char ch) {
    return tolower(ch);
}
int main() {
    int choice;
    string str1, str2, input;
    char ch;
    do {
        cout << "\n===== STRING OPERATIONS MENU =====";
        cout << "\n1. Concatenate two strings";
        cout << "\n2. Reverse a string";
        cout << "\n3. Delete vowels from a string";
        cout << "\n4. Sort characters of a string";
        cout << "\n5. Convert uppercase character to lowercase";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter first string: ";
                cin >> str1;
                cout << "Enter second string: ";
                cin >> str2;
                cout << "Concatenated String: " << concat(str1, str2) << endl;
                break;
            case 2:
                cout << "Enter a string to reverse: ";
                cin >> str1;
                cout << "Reversed String: " << reverse_str(str1) << endl;
                break;
            case 3:
                cout << "Enter a string: ";
                cin >> input;
                cout << "String without vowels: " << delVowels(input) << endl;
                break;
            case 4:
                cout << "Enter a string to sort: ";
                cin >> str1;
                cout << "Sorted String: " << sort_str(str1) << endl;
                break;
            case 5:
                cout << "Enter an uppercase character: ";
                cin >> ch;
                cout << "Lowercase: " << upp_to_low(ch) << endl;
                break;
            case 6:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while(choice != 6);
    return 0;
}
