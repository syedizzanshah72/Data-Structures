#include<iostream>
using namespace std;
class Node{
    public:
    int value;
    Node* next;
    Node(int value){
        this->value = value;
        next = NULL;
    }
};
class StackList{
    private:
    Node* top;
    public:
    StackList(){
        top = NULL;
    }
    void push(int value){
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }
    void pop(){
        if(top == NULL){
            cout << "Stack Is Empty ";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    void Display(){
        Node* curr = top;
        while(curr != NULL){
            cout << curr->value <<endl;
            curr = curr->next;
        }
    }
};
int main(){
    StackList s1;
    s1.push(89);
    s1.push(98);
    s1.push(76);
    s1.Display();

    return 0;
}