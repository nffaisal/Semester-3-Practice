#include<iostream>
using namespace std;
//linked lists beginning traversal and more
struct Node{
    int data;
    Node* next;
};
void countNodes(Node *head){
    Node* current = head;
    //storing the address of the head
    int count =0;
    while(current != nullptr){
        current =current->next;
        count++;
    }
    cout<<"The number of nodes is: "<<count;
}

void findLargest(Node *head){
    Node *current =head;
    Node *largest =head;
    largest->data =0;
    largest->next =nullptr;
    while(current != nullptr){
        if(current->data>largest->data){
            largest=current;
        }
        current =current->next;
    }
    cout<<"The largest node is "<<largest->data;
}

//inserting into the middle
int main(){
   Node *temp;
   Node *head =new Node;
   head->data=10;
   head->next =new Node;

   temp=head->next; //pointing to the second node
   temp->data= 20; //insert into the new node
   temp->next= new Node; //create third node 
    temp=temp->next;

    temp->data=30; //insert data into third 
    temp->next=new Node;
    temp= temp->next;

    temp->data =40;
    temp->next= NULL; //last node

   Node *current; //used for traversal
   current =head; //stroe the value of head at the start and used for traversal
   Node *newNode =new Node;
   newNode->data =25;
   while(current->data !=20){
    current =current->next ;
   }
    newNode->next =current->next;
    current->next = newNode;
    current= head;
  
  //now deleting 30
  while(current->data !=25){ //so now current hold 30
       current = current->next;
   }
   Node *deleteme=current->next;
   current->next= current->next->next;

   delete deleteme;
   current =head;

   while(current !=NULL){ //for printing
    cout<<current->data<<" ";
    current = current->next;
  }
  current =head;




}