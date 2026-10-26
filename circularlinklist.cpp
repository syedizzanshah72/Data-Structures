#include<iostream>
using namespace std;
class Node{
    public:
    int value;
    Node* next;
    Node(int data){
        value = data;
        next = NULL;
    }
};
class List{
    private:
    Node* head ;
    Node* tail;
    List(){
        head=tail=NULL;
    }
    void insertAtStart(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head=tail=newNode;
            newNode->next = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
        tail->next = newNode;
    }

    void insertAtEnd(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head=tail=newNode;
            newNode->next = newNode;
            return;
        }
        tail->next = newNode;  
        tail = newNode;
        newNode->next = head;
    }
    void insertBetween(int val,int afterVal){
        Node* temp = head ;
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            return;
        }
        while(temp != head && temp->value != val){
             temp = temp->next;
        }
        if(temp == head){
            cout<<"Value not found";
        }else{
            newNode->next = temp->next;
            temp->next = newNode;
            
        }
    }

};