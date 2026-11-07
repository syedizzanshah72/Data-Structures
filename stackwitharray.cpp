#include<iostream>
using namespace std;
const int capacity = 10;
class StackArray{
    private:
    int stackArr[capacity];
    int top;
    public:
    StackArray(){
        top=0;
    }
    void push(int value){
        if(top == capacity){
            cout << "Stack is full ";
            return;
        }
        stackArr[top]=value;
        top++;
    }
    void pop(){
    if(top == 0){
        cout << "Stack is empty ";
        return ;
    }
    top--;
    }
    void display(){
    for(int i=top-1;i>=0;i--){
        cout << stackArr[i];
        cout << endl;
    }
    }
};

int main(){
    StackArray s1;
    s1.push(50);
    s1.push(80);
    s1.display();
    cout << "Before Pop " <<endl;
    s1.pop();
    s1.display();
    cout << "After Pop ";
    return 0;
}