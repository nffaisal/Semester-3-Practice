#include<iostream>
using namespace std;

struct node{
    node* next;
    node*prev;
    int data;
};
void printforwar(node*head){
    node *temp=head;
    while(temp !=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void printreverse(node*tail){
    node *temp =tail;
    while(temp !=NULL){
        cout<<temp->prev<<" ";
        temp =temp->prev;
    }
}
int main(){
   node*head;
   node *tail;
   node*n;

   n =new node;
   n->data=1;
   n->prev=NULL;
   head =n;
   tail=n;

   n=new node;
   n->data =20;
   n->prev=tail;
   tail->next =n;
   tail =n;

   n =new node;
   n->data=3;
   n->prev= tail;
   tail->next=n;
   tail =n;
    n =new node;
    n->data =4;
    n->prev=tail;
    tail->next=n;
    tail =n;
    tail->next =NULL;
    n =new node;
    n->data=5;
    n->prev=tail;
    tail->next=n;
    tail = n;
    n->next=NULL;
    if(head!=nullptr){
        head->prev=n;

    }else{
        tail=n;

    }
    head=n;
    

}