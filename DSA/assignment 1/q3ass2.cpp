#include <iostream>
using namespace std;
int linear(int arr[], int n)
{
    int exSum = n * (n + 1) / 2;
    int actualSum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        actualSum += arr[i];
    }
    return exSum - actualSum;
}
int binary(int arr[], int n)
{
    int low = 0, high = n - 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == mid + 1)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low + 1;
}
int main()
{
    int choice, size;
    cout << "Enter the sequence (with one number missing).\n";
    cout << "Enter size of sequence: ";
    cin >> size; 
    int arr[size-1];
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int n = size + 1;
    do
    {
        cout << "\n--- MENU ---\n";
        cout << "1. Find Missing Number Linear Time\n";
        cout << "2. Find Missing Number Binary Search \n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int missing = linear(arr, n);
            cout << "Missing number = " << missing << endl;
            break;
        }
        case 2:
        {
            for (int i = 0; i < size - 1; i++)
            {
                for (int j = i + 1; j < size; j++)
                {
                    if (arr[i] > arr[j])
                    {
                        int temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
            int missing = binary(arr, n);
            cout << "Missing number (Binary Search) = " << missing << endl;
            break;
        }
        case 3:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 3);
    return 0;
}