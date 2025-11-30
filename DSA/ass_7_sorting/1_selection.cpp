#include <bits/stdc++.h>
using namespace std;
void selectionSort(int arr[], int n) {
    int min;
    for (int i = 0; i < n-1; i++) {
        min = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min!=i) {
            swap(arr[i], arr[min]);
        }
    }
}
int main() {
    int arr[5] = {10, 2, 54, 1, 3};
    selectionSort(arr, 5);
    for (int i : arr) {
        cout << i <<" ";
    }
    return 0;
}