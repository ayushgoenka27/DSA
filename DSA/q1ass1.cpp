#include<iostream>
using namespace std;
int n=0;
int arr[100];

void create() {
    cout << "Enter number of elements: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}
void display(){
    cout << "Array Elements : " << endl;
    for(int i=0;i<n;i++){
        cout << arr[i] << endl;
    }
}
void insert(){
    int idx,num;
    cout << "Enter the index: "  ;
    cin >> idx;
    cout << "Enter the number: "   ;
    cin >> num;
     for(int i=n-1;i>=idx;i--){
        arr[i+1]=arr[i];
        
    }
    arr[idx]=num;
    n++;
    for(int i=0;i<n;i++){
        cout << arr[i] << endl;
    }
}
void delElem(){
    int idx;
    cout << "Enter position to delete : ";
    cin >> idx;
    for(int i=idx-1;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    n--;

}
void linSearch(){
    int x;
    cout << "Enter value to search: ";
    cin >> x;
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            cout << "Element found : " << arr[i] << endl;
        }
    }
}
int main(){
    int choice;
    do {
        cout << "\n——MENU——\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert(); break;
            case 4: delElem(); break;
            case 5: linSearch(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while(choice != 6);
    return 0;
}