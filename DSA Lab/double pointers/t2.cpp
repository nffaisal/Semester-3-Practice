#include<iostream>
using namespace std;
//Problem 10 — Resize an Array and write a function for resizing an array using double pointers


void resizeArray(int **arr,int oldsize,int newsize){

        if(oldsize<newsize){
            int *newarr=new int[newsize];
            for(int i=0;i<oldsize;i++){
                newarr[i] = (*arr)[i];
            }
             delete *arr;
         *arr=newarr;
        }
       
}
int main(){

 int size =3;
 int *arr= new int[size];
 for(int i=0;i<size;i++){ arr[i] =i;}
 cout<<"Enter a new size: ";
 int n;
 cin>>n;
 int *newarr = new int[n];
 for(int i =0;i<size;i++){ newarr[i]=arr[i]; }

 newarr=arr;
 for(int i =0;i<n;i++){ cout<<newarr[i]<<" "; }
    resizeArray(&arr, 3,5);
 for(int i =0;i<n;i++){ cout<<arr[i]<<" "; }
 
}