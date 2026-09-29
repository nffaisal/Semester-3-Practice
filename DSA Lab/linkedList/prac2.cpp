#include<iostream>
using namespace std;
//linked lists beginning traversal and more
struct Node{
    int data;
    Node* next;
};

int main(){
   Node *temp;
   Node *head;
   Node *start;
   Node *current;
  head = new Node;
  head->data =10;
  head->next =new Node;
  start =head;
  temp=head->next;
  temp->data=20;
  temp->next=new Node;
  temp =temp->next;
  temp->data=30;
  temp->next =NULL;
    //inserting a new node
  Node *newHead= new Node;
  newHead->next=start;
  newHead->data=0;

  current=newHead; //so we dont lise the new head
//now we are trying to insert a node at the end
   Node *lastnode =new Node;
   lastnode->data=40;
     lastnode->next=NULL;
    while(current->next != NULL){
    current = current->next; //reached the last node 
}

current->next = lastnode; //update it to point it to the new last node
  //reset the current head back to start from newhead
  current=newHead;
  while(current !=NULL){ //for printing
    cout<<current->data<<" ";
    current = current->next;
  }



}