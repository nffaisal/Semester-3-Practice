#include<iostream>
using namespace std;

struct node{
    node* next;
    node*prev;
    int data;
};
int main(){
    node *Head=new node;
    node *temp;
    Head->data=10;
    Head->prev =NULL;
    Head->next=new node;
    temp =Head->next;
    temp->prev=Head;
    temp->data =20;
    temp->next= new node;
    node*temp2 =temp->next;
    temp2->data=30;
    temp2->prev=temp;
    temp2->next=new node;
    temp=temp2->next;
    temp->data =40;
    temp->prev= temp2;
    temp->next=NULL;
 node *head;
    node*tail;
    node *temp;
    head = new node;
    head->data =10;
    head->prev=NULL;
    head->next= new node;
    temp =head->next;
    temp->data =20;
    temp->prev =head;
    temp->next =new node;
    temp= temp->next;
    temp->prev=temp;
    temp->data=30;
    temp->next= NULL;
    
    while(temp !=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    } 



}