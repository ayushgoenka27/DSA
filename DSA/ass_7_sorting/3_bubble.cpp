#include <bits/stdc++.h>
using namespace std;
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
int main() {
int arr[5] = {10, 2, 54, 1, 3};
    bubbleSort(arr, 5);
    for (int i : arr) {
        cout << i <<" ";
    }
    return 0;
}