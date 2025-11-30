#include <bits/stdc++.h>
using namespace std;
void insertionSort(int arr[], int n) {
    int temp, j;
    for (int i = 1; i < n; i++) {
        temp = arr[i];
        j = i;
        while(arr[j-1] > temp && j > 0) {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = temp;
    }
}
int main() {
    int arr[5] = {10, 2, 54, 1, 3};
    insertionSort(arr, 5);
    for (int i : arr) {
        cout << i <<" ";
    }

    return 0;
}