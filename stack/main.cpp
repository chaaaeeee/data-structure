#include <iostream>

const int MAX_SIZE = 5;

class Stack {
private: 
    char arr[MAX_SIZE];
    int top;
public:
    Stack() {
        top = -1;
    }

    bool IsEmpty() {
        return(top == -1);
    }

    bool IsFull() {
        return(top == MAX_SIZE-1);
    }

    void Push(char element) {
        if(!IsFull()) {
            top++;
            arr[top] = element;
            std::cout << "Pushed " << element << " into the Stack..." << std::endl;
        } else {
            std::cout << "Stack is full, can't push the element..." << std::endl;
        }
    } 

    void Pop() {
        if(!IsEmpty()) {
            char popped = arr[top];
            top--;
            std::cout << "Popped last element of the Stack : " << popped << std::endl;
        } {
            std::cout << "Stack is empty, can't find the last element of the Stack" << std::endl;
        }
    }

    char GetTopElement() {
        return arr[top];
    }

    void PopWithoutMsg() {
        if(!IsEmpty()) {
            char popped = arr[top];
            top--;
        }
    }


    void Reverse() { // cout right away, should be printReversed
        char popped;
        while(!IsEmpty()){
            popped = arr[top];
            std::cout << popped;
            PopWithoutMsg();
        }
    }

    void ReverseAgain() { // actual reverse, bcs it's pushed back into the Stack
        char popped;
        int index = 0;
        char reversed[MAX_SIZE] = {};
        while(!IsEmpty()) {
            reversed[index] = arr[top];
            index++;
            PopWithoutMsg();
            // need variabels to store popped that's accessible outside the loop
        }

        for(int i = 0; i < index; i++) {
            Push(reversed[i]);
        }

    }

    void Print() {
        for(int i = 0; i < MAX_SIZE && arr[i]; i++){
            std::cout << arr[i]; 
        }
    }
};

int main() {
    Stack stk;
    stk.Push('b');
    stk.Push('a');
    stk.Push('d');

    stk.ReverseAgain();
    stk.Print();

    return 0;
}
