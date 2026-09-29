#include<iostream>
#include<cstring>
using namespace std;
/*
10: Create two functions to double the price of a Book struct object: one taking Book& and the other taking Book*.

Concepts Tested: Pass by reference vs. pointer syntax, parameter checking.

Hint: Ensure the pointer version verifies b != nullptr before performing arithmetic*/

struct book{
    float price;
    string name;

};
void doublePrice(book &b){
    b.price *= 2;
    cout<<"\n New price:"<<b.price;

}
void doubleprice(book *b){
 if(b != NULL){
    b->price *=2;
    cout<<"price: "<<b->price;
 }
}
void details(book &book)
{
    cout<<"Enter Book details: \n";
    getline(cin,book.name);
    cout<<"enter Book Price: ";
    cin>>book.price;
}
int main(){
    book *b1 =new book;
    details(*b1);
    doublePrice(*b1);
    doubleprice(b1);
    delete b1;
    b1= NULL;

    
}