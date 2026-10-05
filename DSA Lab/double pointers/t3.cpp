#include<iostream>
using namespace std;
//Problem 11- dynamic array and do insertion at any point user asks

void resizearray(int **arr, int oldsize,int newsize,int newvalue,int index){
   
        int *newarr=new int[newsize];
        for(int i=0;i<newsize;i++){
            if(i < index)
        {
            newarr[i] = (*arr)[i];
        }
        else if(i == index)
        {
            newarr[i] = newvalue;
        }
        else
        {
            newarr[i] = (*arr)[i - 1]; //old element moves one position to the right
        }
        }
        delete []*arr;
            *arr =newarr;
    
    for(int i=0;i<newsize;i++){
        cout<<newarr[i]<<" ";
    }
}

int main(){
   int n,index,size,value;
   cout<<"ENter size of array";
   cin>>size;
   int *arr= new int[size];
   for(int i =0;i<size;i++){
    cin>>value;
    arr[i] =value;
   }
   cout<<"ENter value: ";
   cin>>n;
   cout<<"Enter index";
   cin>>index;
   resizearray(&arr,size,size+1,n,index);
   delete []arr;
}