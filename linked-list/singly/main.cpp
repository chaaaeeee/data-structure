#include <iostream>

struct Node{
    int Data;
    Node* Next; 
};

class LinkedList{
    Node* Head;

public:
    LinkedList() : Head(NULL) {}

    void insertAtFirst(int value) {
        Node* newNode = new Node();

        newNode->Data = value;
        newNode->Next = Head;

        Head = newNode;
    };

    void insertAtLast(int value) {
        Node* newNode = new Node();
        
        newNode->Data = value;
        newNode->Next = NULL;

        Node* temp = Head;

        while(temp->Next) {
            temp = temp->Next;
        };

        temp->Next = newNode; 
    }

    void insertAtPosition(int position, int value) {
        if(!Head) {
            std::cout << "no head for u lil bro";
        }

        Node* newNode = new Node();
        newNode->Data = value;

        Node* temp = Head;
        for(int i = 1; i < position-1 && temp; i++) {
            temp = temp->Next;
        }

        newNode->Next = temp->Next;
        temp->Next = newNode;
    }

    void deleteAtFirst() {
        if(!Head) {
            std::cout << "there is no head for u lil bro u broke asf";
        }
        Node* temp = Head;
        Head = temp->Next;
        delete temp;
    }

    void deleteAtLast() {
        if(!Head) {
            std::cout << "there is no head for u lil bro u broke asf";
        }
        
        Node* temp = Head;
        while(temp->Next->Next) { // peek 2 kedepan
            temp = temp->Next; //
        }; // hasilnya 1 node sebelum last node

        delete temp->Next;
        temp->Next = NULL;

    }
    
    void len() {
        Node* temp = Head;

    }

    void print() {
        if(!Head) {
            std::cout << "no head for u lil bro";
        }
        Node* temp = Head;

        while(temp) {
            std::cout << temp->Data << " -> ";
            temp = temp->Next;
        }
    }
};

int main() {
    LinkedList list;

    list.insertAtFirst(5);
    list.insertAtFirst(4);
    list.insertAtFirst(3);
    list.insertAtFirst(2);
    list.insertAtFirst(1);
    list.insertAtPosition(3, 69);
    list.deleteAtLast();
    list.print();

    return 0;
}

