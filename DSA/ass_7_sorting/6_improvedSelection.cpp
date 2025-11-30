#include <bits/stdc++.h>
using namespace std;

void improvedSelectionSort(vector<int>& arr) {
    int n = arr.size();
    int left = 0;
    int right = n - 1;
    
    while (left < right) {
        int minIndex = left;
        int maxIndex = left;
        
        for (int i = left; i <= right; i++) {
            if (arr[i] < arr[minIndex]) {
                minIndex = i;
            }
            if (arr[i] > arr[maxIndex]) {
                maxIndex = i;
            }
        }
        
        swap(arr[left], arr[minIndex]);
        
        if (maxIndex == left) {
            maxIndex = minIndex;
        }
        
        swap(arr[right], arr[maxIndex]);
        
        left++;
        right--;
    }
}

int main() {
    vector<int> arr = {4, 2, 1, 7, 9, 10, 8};
    int n = arr.size();
    improvedSelectionSort(arr);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}