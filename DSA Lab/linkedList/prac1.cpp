#include<iostream>
using namespace std;
//linked lists beginning traversal and more
struct Node{
    int data;
    Node* next;
};

int main(){
    Node *temp;
    Node *head =new Node;
    head->data =1;
    head->next =new Node;
    temp= head->next;
    temp->data =2;
    temp->next=new Node;
    temp =temp->next;
    temp->data=3;
    temp->next=NULL;
    Node *current =head;
    //traversal
    while(current !=NULL){
        cout<< current->data<<" ";
        current=current->next;
    }


}