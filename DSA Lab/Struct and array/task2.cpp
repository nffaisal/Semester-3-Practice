/* Write a function int searchBookByID(const Book *arr, int size, int targetID) that returns the index of the matching book or -1 if missing.

Concepts Tested: Array of structs search, returning match indices.

Hint: Loop from 0 to size - 1 comparing arr[i].id == targetID. */
#include<iostream>
#include<cstring>
using namespace std;


struct book{
    int bookID;
    float price;
    string name;

};

int searchBooksByID(const book *arr, int size, int targetID){
    for(int i =0;i<size; i++){
        if(arr[i].bookID == targetID){
            return arr[i].bookID;
        }
    }
    return -1;
}
void details(book &book)
{
    cout<<"Enter Book details: \n";
    getline(cin,book.name);
    cin.ignore();
    cout<<"enter Book Price: ";
    cin>>book.price;
}
void detailsBookArray(book*arr,int size){
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
    int n =4;
    book *books =new book[4];
      detailsBookArray(books,n);
    cout<<"enter target ID";
    int target;
    cin>>target;
    cout<< searchBooksByID(books, n,target);

    
}