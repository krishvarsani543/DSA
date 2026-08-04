#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int val){
          data=val;
          next=NULL;
    }
};
class linklist{
    public:
    Node* head;
    Node* tail;
    linklist(){
        head=tail=NULL;
    }

   // INSEART AT THE FRONT ::

   void push_front(int val){
    Node* newNode=new Node(val);
    if(head==NULL){head=tail=newNode;return;}
    newNode->next=head;
    head=newNode;
   }


   // INSEART AT THE END ::

   void push_back(int val){
    Node* newNode=new Node(val);
    Node* temp=head;
    if(head==NULL){
        head=newNode;
        return;
    }

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
   
   }
    
   // INSEART AT ANY RANDOM POSITION ::

    void push_random(int pos,int val){
        Node* newNode=new Node(val);
        Node* temp=head;
        if(head==NULL){
            head=newNode;
            return;
        }
        if(pos==1){
            newNode->next=head;
            head=newNode;
        }

        for(int i=1;i<pos-1&&temp!=NULL;i++){
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
       
    }
   
    // DELETE AT THE FRONT ::

    void pop_front(){
        if(head==NULL){
            cout<<"NO LIST FOUND";
        }
        Node* temp=head;
        head=temp->next;
       delete temp;
    }

    // DELETE AT THE END ::

    void pop_back(){
        Node* temp=head;
        if(head==NULL){
            cout<<"NO LIST FOUND";
        }
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        delete temp->next;
        temp->next=NULL;
    }

    // DELETE AT ANY POSITION ::

    void pop_random(int pos){
        Node* temp=head;
        if(head==NULL){
            cout<<"NO LIST FOUND";
        }
        for(int i=1;i<pos-1&&temp!=0;i++){
            temp=temp->next;
        }

        Node* Del=temp->next;;
        temp->next=Del->next;
        delete Del;
    }
    
    // REVERSE LINKED LIST ::

    void reverse(){
          Node* curr=head;
          Node* prev=NULL;
          Node* next=NULL;
          while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;

          }
    }

    //REVERSE LINKLIST PRINT

    void reverseprint(Node* temp){
         if(temp==NULL){
            cout<<"-->";
            return;
         }
         reverseprint(temp->next);
         cout<<temp->data<<"-->";
    }

   // DISPLAY LINKEDLIST ::

   void display(){
      Node* temp=head;
      while(temp!=NULL){
        cout<<temp->data<<"-->";
        temp=temp->next;
      }
      cout<<"NULL";
   }

};
int main(){
    linklist l;
    l.push_front(30);
    l.push_back(40);
    l.push_back(50);
    l.push_back(70);
     l.push_back(80);
      l.push_back(90);

    l.push_random(2,20);
    l.pop_front();
    l.pop_back();
    l.pop_random(3);
    l.reverseprint(l.head);
    l.display();
    l.reverse();
}