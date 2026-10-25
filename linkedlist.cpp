#include<iostream>
using namespace std;
// node class contains important variables and data 
class Node{
    public:
    int data;
    Node* next;
    Node(int value){
        data=value;
        next=NULL;
    }
};

// list class contains methods and things of implememtation

class List{
public:
Node* head;
List(){
    head = NULL;
}
// This method is used to insert the node at the start 

void insertAtStart(int value){
    Node* newNode = new Node(value); // creating new Node , having value null of next and newNode have address of the new Node

    newNode->next = head; // giving value of head means head value to new node next 
    head = newNode; // head have address of first node now 
}

// It is used to insert value at end 
void insertAtEnd(int value){
    Node* newNode = new Node(value);// creating new node and newNode have address of that 
    Node* temp = head; // creation of temp variable as head is important and we  dont want to lose control of head 

    if(head == NULL){ // if there's no node before 
        head = newNode;
        return;
    }
    while(temp->next != NULL){ // condition there's as you have to traverse till end as there's no direct access to last index 

        temp = temp->next; // traversing 
    }
    temp -> next = newNode; // after getting last spot just send the thing
}

// it is used to insert the values between 

void insertBetweenTwoNodes(int value , int afterValue){ //in this you have to tell after which value you wanna insert
    Node* newNode = new Node(value);
    Node* temp= head; // some of the same steps 
    while(temp != NULL && temp -> data != afterValue){ // it stops when it have the access the node of the after value 
        temp = temp->next; // otherwise marching towards destination
    }
    if(temp == NULL){
        cout << "Value not found in the linkedlist";
    }
    newNode -> next = temp ->next; // newnode next is setted first 
    temp -> next = newNode; // then back is attached 
}

// to delete a node on the basis of a value 

void deleteANode(int value){
// if you want to delete the head 

Node* temp = head;
head = head->next;
delete temp;

// if there's node between or at the end 


while(temp != NULL && temp -> next -> data != value){ // next ka next agar hum usi node pa phoch jayein to hum address lost kardein ga is lia aik pehlay 
    temp = temp -> next;
}
if(temp == NULL){  // if it's NULL
    cout << "Value not found";
}

// delete requires two temp like variables 
Node* del = temp->next;
temp->next = del->next;
delete del;
}

void SearchNode(int val){
    if(val == head->data){
        cout << "Value find at first index";
        return;
    }
    int count = 0;
    Node* temp = head;
    while(temp->data != val){
        temp = temp->next;
        count++;
    } 
    if(temp->data == val){
        cout << "Value found at index " <<count;
        return;
    }else{
        cout << "Value not found " <<endl;
    }
}

// Traversing the list 

void display(){
    Node* temp = head;
    cout << "List: ";
    while(temp != NULL){
        cout << temp->data << "->";
        temp=temp->next;
    }
    cout << "NULL "<<endl;
}
};
    


int main(){
    List l ;
    l.insertAtStart(20);
    l.insertAtEnd(50);
    l.insertAtEnd(100);
    l.insertAtEnd(40);
    l.insertAtStart(92);
    l.insertBetweenTwoNodes(90,100);
    l.SearchNode(50);
    l.display();

    return 0;
}