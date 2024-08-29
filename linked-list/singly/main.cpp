#include <iostream>

struct Node{
    int Data;
    Node* Next; 
};

class LinkedList{
    Node* Head;

public:
    LinkedList() : Head(NULL) {}

    // getter since Head is private
    Node* getHead() {
        return Head;
    }

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

    void deleteAtPosition(int position) {
        if(!Head) {
            std::cout << "no head for u lil bro";
        }

        Node* temp = Head;
        if(position == 1) {
            Head = temp->Next;
        }

        for(int i = 1; i < position-1 && temp; i++) { // what if it does not founda anything lol
            temp = temp->Next;
        }

        temp->Next =  temp->Next->Next;
    }
    
    // len with iteration
    int len() {
        if(!Head){
            return 0;
        }

        Node* temp = Head;

        int len = 0;
        while(temp) {
            len++;
            temp = temp->Next;
        }

        return len;
    }

    // len with recursive
    int lenRecursively(Node* temp) {
        if(!temp){
            return 0;
        }

        return 1 + lenRecursively(temp->Next);
    }

    bool find(int value) {
        if(!Head){
            return false;
        }

        Node* temp = Head;

        while(temp) {
            temp = temp->Next;
            if(temp->Data == value) {
                return true;
            }
        }

        return false;
    } 

    bool findRecursively(int value, Node* temp) {
        // if temp is null then there's nothing, so false
        if(!temp) {
            return false;
        }
        
        if(temp->Data == value) { // if it matches, then true
            return true;
        } else {
            return findRecursively(value, temp->Next); // if it is not, then do it again, until !temp is null until it meets the condition on the top
        }
    }

    Node* reverse() {
        Node* prev = new Node();
        Node* curr = Head;;
        Node* next = new Node();

        while(curr != nullptr){
            next = curr->Next;
            curr->Next = prev;
            prev = curr;
            curr=next;
        }

        return prev;
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

    void printWithHead(Node* head) {
        if(!head) {
            std::cout << "no head for u lil bro";
        }
        Node* temp = head;

        while(temp) {
            std::cout << temp->Data << " -> ";
            temp = temp->Next;
        }
    }
};

int main() {
    LinkedList list;

    std::cout << "initialization..." << std::endl;
    list.insertAtFirst(5);
    list.insertAtFirst(4);
    list.insertAtFirst(3);
    list.insertAtFirst(2);
    list.insertAtFirst(1);
    list.insertAtFirst(1);
    list.insertAtFirst(1);
    list.insertAtFirst(1);
    std::cout << "list before reversion :" << std::endl;
    std::cout << "ini print" << std::endl;
    list.print();
    
    std::cout << std::endl;
    /*

    std::cout << "list after reversion :" << std::endl;
    Node* prev = new Node();
    prev = list.reverse();
    list.printWithHead(prev);
    */

    std::cout << std::endl;

    std::cout << "len : " << list.len();
    std::cout << std::endl;

    Node* head = list.getHead();
    std::cout << "len recursively : " << list.lenRecursively(head);
    std::cout << std::endl;

    int findmeubastard = 5;
    int whereami = 6;
    bool isExist = list.find(findmeubastard);
    if(isExist) {
        std::cout << "he(" << findmeubastard << ") is HIM";
    } else {
        std::cout << "unfortunately, he's(" << findmeubastard << ") not";
    }
    std::cout << std::endl;

    isExist = list.findRecursively(whereami, head);
    if(isExist) {
        std::cout << "he(" << whereami << ") is HIM";
    } else {
        std::cout << "unfortunately, he's(" << whereami << ") not";
    }
    std::cout << std::endl;

    return 0;
}

