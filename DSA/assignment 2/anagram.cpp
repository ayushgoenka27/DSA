#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string str1, str2;
    cout<<"Enter string 1 : ";
    cin >> str1;
    cout<<endl;
    cout<<"Enter string 2 : ";
    cin >> str2;

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    if (str1 == str2) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}