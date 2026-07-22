#include<iostream>
using namespace std;
int main(){
    string s[200];
    int n;
    cout<<"enter number of item";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    int h;
    cout<<"enter number of rotation : ";
    cin>>h;
    h%=n;
    for(int i=h;i<n;i++)
    cout<<s[i];
    for(int i=0;i<h;i++)
    cout<<s[i];
}
//while(i<k){
//
//swap(arr[i],arr[n-i]);
//i++;}
//i=k;
//while(i<n){
//swap(arr[i],arr[n-i]);
//i++;}
