#include <iostream>
using namespace std;
int countElem(int arr[], int n) {
    int count = 0;
    int i,j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < i; j++) {
            if(arr[i] == arr[j])
                break;
        }
        if(i == j)
            count++;
    }

    return count;
}
int main() {
    int arr[] = {1, 2, 2, 3, 4, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Total distinct elements: " << countElem(arr, n) << endl;
    return 0;
}