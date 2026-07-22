#include<iostream>
using namespace std;
int iterativeBinarySearch(int arr[],int target,int n){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==target) return mid;
        else if(arr[mid]<target) {
            low=mid+1;
            
        }
        else {
            high=mid-1;
        }
    }

}
int recursiveBinarySearch(int arr[],int target,int n,int low,int high){
    int mid=low+(high-low)/2;
    if(arr[mid]==target)return mid;
    else if(arr[mid]<target)return recursiveBinarySearch(arr,target,n,mid+1,high);
    else return recursiveBinarySearch(arr,target,n,low,mid-1);
}
int main(){
    int n;
    cout<<"Enter Number Of Element :";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cout<<"Enter Target :";
    cin>>target;

    int a=iterativeBinarySearch(arr,target,n);
    cout<<"Target At Index :"<<a<<endl;

    cout<<"***************************************"<<endl;
      int low=0;
      int high=n-1;
    int b=recursiveBinarySearch(arr,target,n,low,high);
    cout<<"Target At Index :"<<b<<endl;
}

