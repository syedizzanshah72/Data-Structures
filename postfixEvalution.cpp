#include<iostream>
using namespace std;
const int MAX = 20;
class Stack{
    public:
    int Stac[MAX];
    int top;
    Stack(){
        top = -1;
    }
    void push(int value){
        if(top == MAX-1){
            cout << "Space is full in the stack ";
            return;
        }
        top++;
        Stac[top] = value;
    }
    int pop(){
        if(top == -1){
            cout << "Can't Pop , It's Empty ";
            return -1;
        }
        return Stac[top--];
    }
    int raisetopower(int value,int power){
        int result=1;
        for(int i=1;i<=power;i++){
            result *= value;
        }
        return result;
    }
    int valueOperator(char op , int op1,int op2){
        switch(op){
        case '+':return op2+op1;
        case '-':return op2-op1;
        case '*':return op2*op1;
        case '/':return op2/op1;
        case '^' :return raisetopower(op2,op1);
        }
    }
    int CalculatePostfix(char Postfix[]){
        Stack s1;
        for(int i=0;Postfix[i] != '\0';i++){
            int e = Postfix[i];
            if(e >= '0' && e<='9'){
                s1.push(e-'0');
            }
            else{
                int op1 = s1.pop();
                int op2 = s1.pop();
                int result = valueOperator(e,op1,op2);
                s1.push(result);
            }
        }
        return s1.pop();
    }

};
int main(){
    Stack s;
    char exp[] = "623+-382/+*2^3+";
    cout << "Final Answer: " << s.CalculatePostfix(exp) << endl;

    return 0;
}