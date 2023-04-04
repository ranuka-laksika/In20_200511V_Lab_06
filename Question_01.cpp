#include <iostream>
using namespace std;

#define MAXIMUM 50

class Stack {
    private:
        int arr[MAXIMUM];
        int top;
    public:
        Stack() {
            top = -1;
        }
        bool isEmpty() {
            return (top == -1);
        }
        bool isFull() {
            return (top == MAXIMUM - 1);
        }
        void push(int value) {
            if (isFull()) {
                cout << "Stack Overflow" << endl;
            } else {
                arr[++top] = value;
            }
        }
        int pop() {
            if (isEmpty()) {
                cout << "Stack Underflow" << endl;
                return -1;
            } else {
                return arr[top--];
            }
        }
        int stackTop() {
            if (isEmpty()) {
                cout << "Stack is empty" << endl;
                return -1;
            } else {
                return arr[top];
            }
        }
        void display() {
            if (isEmpty()) {
                cout << "Stack is empty" << endl;
            } else {
                cout << "Elements in the stack are: ";
                for (int i = 0; i <= top; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
        }
};

int main() {
    Stack stac;
    
    stac.push(20);
    stac.push(30);
    stac.push(40);
    stac.push(60);
    
    stac.display();
    cout << "Top of the stack is : " << stac.stackTop() << endl;
    stac.pop();
    cout << "After the pop is: " << stac.stackTop() << endl;
    stac.display();
    cout << "Is the stack empty? " << (stac.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is the stack full? " << (stac.isFull() ? "Yes" : "No") << endl;//it's not full unless the top is 49
    return 0;
}
