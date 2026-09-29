/* Task: Create a function Book* expandArray(Book *oldArr, int oldSize, int newSize) that allocates a new dynamic array of size newSize, copies elements from oldArr, deletes oldArr, and returns the new array.

Concepts Tested: Dynamic array growth, manual element copying, memory migration.

Hint: Loop 0 to oldSize - 1 setting newArr[i] = oldArr[i];, then call delete[] oldArr;. */
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;


struct Book{
    int bookID;
    float price;
    string name;

};

Book* expandArray(Book *oldArr,int oldsize,int newSize){
        Book *newArr = new Book[newSize];
        int elementstocopy =min(oldsize,newSize);
        if(oldArr != NULL){
        for(int i =0;i<elementstocopy;i++){
            *(newArr +i)  = *(oldArr +i);
        }
    }
        delete []oldArr;
    

        return newArr;

}

void details(Book &book)
{
    cout<<"Enter Book details: \n";
    getline(cin,book.name);
    cin.ignore();
    cout<<"enter Book Price: ";
    cin>>book.price;
}
void detailsBookArray(Book*arr,int size){
    for(int i=0;i<size;i++){
        cout<<"enter book "<<i<< " ID: ";
        cin>>arr[i].bookID;
        cout<<"\nenter Book name: ";
        cin.ignore();
        getline(cin,arr[i].name);
        cout<<"\nEnter Book price: ";
        cin>>arr[i].price;
        cout<<endl;
    }
}
int main(){
    
  

    
}