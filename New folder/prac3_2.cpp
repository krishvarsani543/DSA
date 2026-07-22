#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>v={0,1,0,0,2,1,2,0};
    int n=v.size();
    int low=0;
    int mid=0;
    int high=n-1;
    while(low<=high){
        if(v[mid]==0){
            swap(v[low],v[mid]);
        }
    }
}