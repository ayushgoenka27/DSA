#include<iostream>
using namespace std;
int main(){
    int a[10][10],b[10][10],r[10][10];
    int r1,c1,r2,c2;
    cout<<"enter first matrix rows and colmns";
    cin>>r1>>c1;
    cout<<"enter second matrix rows and colmns";
    cin>>r2>>c2;
    if(c1!=r2){
        cout<<"multiplication not possible";
    }
    int i,j;
    cout<<"first matrix:";
    for(i=0;i<r1;i++){
        for(j=0;j<c1;j++){
            cin>>a[i][j];
        }
    }
    cout<<"second matrix:";
    for(i=0;i<r2;i++){
        for(j=0;j<c2;j++){
            cin>>b[i][j];
        }
    }
    for(i=0;i<r1;i++){
        for(j=0;j<c2;j++){
            r[i][j]=0;
        }
    }
    int k;
    for(i=0;i<r1;i++){
        for(j=0;j<c2;j++){
            for(k=0;k<c1;k++){
                r[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    cout<<"multiplied matrix:";
    for(i=0;i<r1;i++){
        for(j=0;j<c2;j++){
            cout<<r[i][j]<<"";
        }
    }
}