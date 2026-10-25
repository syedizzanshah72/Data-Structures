#include<iostream>
using namespace std;
class Node{
    public:
    int value;
    Node* prev;
    Node* next;
    Node(int data){
        value = data;
        prev = NULL;
        next = NULL;
    }
};
class List{
    private:
    Node* head;
    Node* tail;
    public:
    List(){
        head = NULL;
        tail = NULL;
    }
    void InsertAtStart(int value){
        Node* newNode = new Node(value);
        if(head == NULL){
            head=tail=newNode;
            return;
        }
        newNode->next = head;
        head->prev= newNode;
        head = newNode;
    }
    void InsertAtEnd(int value){
        Node* newNode = new Node(value);
        if(tail == NULL){
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev=tail;  
        tail = newNode;
    }
    void insertBetween(int value ,int afterValue){
        Node* newNode = new Node(value);
        Node* temp = head;
        while(temp != NULL && temp->value != afterValue){
            temp = temp->next;
        }
        if(temp == NULL){
            cout << afterValue << "is not found at all";
            return;
        }
        newNode->prev = temp;
        newNode->next = temp->next;
        if(temp->next != NULL){
            temp->next->prev = newNode;

        }else{
            tail=newNode;
        }
        temp->next= newNode;

    }
    void Display(){
        Node* temp = head;
        while(temp != NULL){
             cout << temp->value << " ";
            temp = temp->next;

        }
    }
};
int main(){
    List l1 ;
    l1.InsertAtStart(50);
    l1.InsertAtEnd(20);
    l1.InsertAtEnd(97);
    l1.insertBetween(0,50);
    l1.Display();

    return 0;
}