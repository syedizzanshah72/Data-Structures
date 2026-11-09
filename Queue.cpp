#include<iostream>
using namespace std;
class Queue{
    public:
    int value;
    Queue* next;
    Queue(int data){
        value = data;
        next = NULL;
    }
};
class List{
    private:
    Queue* front;
    Queue* rear;
    public:
    List(){
        front = NULL;
        rear = NULL;
    }
    void Enqueue(int val){
        Queue* queue = new Queue(val);

        if(front == NULL){
            front = rear = queue;
            return;
        }
        rear->next = queue;
        rear = queue;
    }
    void dequeue(){
        Queue* curr = front;
        if(curr != NULL){
        front = front->next;
        delete curr;
        }else{
        cout << "It is empty ";
        }
        if (front == NULL) {
            rear = NULL;
        }
    }
    void display(){
        Queue* curr = front;
        while(curr != NULL){
            cout << curr->value << endl;
            curr = curr->next;
        }
    }
    

};
int main(){
    List l1;
    l1.Enqueue(89);
    l1.Enqueue(87);
    l1.Enqueue(86);
    l1.Enqueue(97);
    l1.dequeue();
    l1.display();
    return 0;
}