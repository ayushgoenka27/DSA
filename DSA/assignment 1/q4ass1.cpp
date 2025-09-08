#include<iostream>
using namespace std;
int main(){
    int arr[100],n;
    cout<<"enter no. of elements:";
    cin>>n;
    int i;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    int start = 0, end = n - 1;
    while(start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
    for(i=0;i<n;i++){
        cout<<arr[i];
    }
}