#include<iostream>
using namespace std;
//reverse an array
//Reverse an Array Using Pointers step by step, but I'll make you do the important part.
int main(){
 int arr[]={10,20,30,40,50};
 int *p =arr;
 int *left =arr;
 int *right=arr+4;
 int temp =0;
 
 while(left<right){
    temp =*left;
    *left=*right;
    *right =temp;
    right--;
    left++;
 }
 for(int i=0;i<5;i++){
    cout<<arr[i]<<" ";
 }


}