#include <iostream>

class Node {
    public: 
        int data;
        Node* left, * right;
        
        Node(int key) {
            data = key;
            left = nullptr;
            right = nullptr;
        }
};

int main() {
    Node* firstNode = new Node(1);
    Node* secondNode = new Node(2);
    Node* thirdNode = new Node(3);
    Node* fourthNode = new Node(4);

    firstNode->left = secondNode;
    firstNode->right = thirdNode;
    secondNode->left = fourthNode;

    return 0;
}

