#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr,int low, int high) {
    int pivot = arr[high];
    int i = low-1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pivot_index = partition(arr, low, high);
        quickSort(arr, low, pivot_index-1);
        quickSort(arr, pivot_index + 1, high);
    }
}

int main() {
    vector<int> arr = {4, 2, 1, 7, 9, 10, 8};
    int n = arr.size();
    quickSort(arr, 0, n-1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    } 

    return 0;
}