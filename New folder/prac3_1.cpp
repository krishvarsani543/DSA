#include<iostream>
#include<vector>
using namespace std;
void bubbleSort(vector<int>&v){
    int n=v.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(v[j]>v[j+1]){
                int temp=v[j];
                v[j]=v[j+1];//swap(v[j],v[j+1]);
                v[j+1]=temp;
            }
        }
    };
    cout<<"Sorted Array : ";
    
    for (int i=0;i<n;i++){
               cout<<v[i]<<" ";
    }
    cout<<endl;
   
}
void insertionSort(vector<int>&v){
    int n=v.size();
    for(int i=1;i<n;i++){
        int key=v[i];
       int j=i-1;
        while(j>=0&&v[j]>key){
            v[j+1]=v[j];
            j-=1;
        }
       v[j+1]=key;
    }
    cout<<"Sorted Array : ";
    for (int i=0;i<n;i++){
               cout<<v[i]<<" ";
    }
    cout<<endl;
}
void selectionSort(vector<int>&v){
    int n=v.size();
           for(int i=0;i<n-1;i++){
            int min=i;
            for(int j=i+1;j<n;j++){
                if(v[j]<v[min]){
                    min=j;
                }

            }
            swap(v[i],v[min]);
           }
           cout<<"Sorted Array : ";
    for (int i=0;i<n;i++){
               cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int>a={25,17,31,13,2};
    cout<<"Bubble Sort "<<endl;
    bubbleSort(a);
    cout<<"***************"<<endl;
    cout<<"Insertion Sort "<<endl;
    insertionSort(a);
    cout<<"***************"<<endl;
    cout<<"Selection Sort "<<endl;
    selectionSort(a);


}