
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

#define MAXIMUM 50
int stack_count=1;
/////////////////////////Stack implementation using array/////////////////////////////////////

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

/////////////////Stack implementation using LinkedList/////////////////////////////////
class Node {
public:
    int data;
    Node* next;
};

class Stack1 {
private:
    Node* top;
public:
    Stack1() {
        top = nullptr;
    }

    bool isEmpty() {
        return (top == nullptr);
    }

    bool isFull() {
        Node* tempary = new Node();
        if (tempary == nullptr) {
            delete tempary;
            return true;
        } else {
            delete tempary;
            return false;
        }
    }

    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return -1;
        } else {
            int value = top->data;
            Node* temp = top;
            top = top->next;
            delete temp;
            return value;
        }
    }

    int stackTop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        } else {
            return top->data;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Elements in the stack are: ";
            Node* temp = top;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};
/////////////////////////////////////////////////////////////////////////////////////

int main() {
    if (stack_count==1){
    auto start = high_resolution_clock::now();
    Stack stac;
    stac.push(8);
    stac.push(10);
    stac.push(5);
    stac.push(11);
    stac.push(15);
    stac.push(23);
    stac.push(6);
    stac.push(18);
    stac.push(20);
    stac.push(17);
    stac.display();
    for (int i=0;i<5;i++){
        stac.pop();
    }
    stac.display();
    stac.push(4);
    stac.push(30);
    stac.push(3);
    stac.push(1);
    stac.display();
   
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Execution time (Implemetation using the array): " << duration.count() << " microseconds" << endl;

    // cout << "Top of the stack is : " << stac.stackTop() << endl;
    // stac.pop();
    // cout << "After the pop is: " << stac.stackTop() << endl;
    // stac.display();
    // cout << "Is the stack empty? " << (stac.isEmpty() ? "Yes" : "No") << endl;
    // cout << "Is the stack full? " << (stac.isFull() ? "Yes" : "No") << endl;//it's not full unless the top is 49
    stack_count+=1;
    }
    if (stack_count==2){
    auto start = high_resolution_clock::now();
    Stack1 stac1;
    stac1.push(8);
    stac1.push(10);
    stac1.push(5);
    stac1.push(11);
    stac1.push(15);
    stac1.push(23);
    stac1.push(6);
    stac1.push(18);
    stac1.push(20);
    stac1.push(17);
    stac1.display();
    for (int i=0;i<5;i++){
        stac1.pop();
    }
    stac1.display();
    stac1.push(4);
    stac1.push(30);
    stac1.push(3);
    stac1.push(1);
    stac1.display();
   
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Execution time (Implemetation using the LinkedList): " << duration.count() << " microseconds" << endl;
    }
    return 0;
}