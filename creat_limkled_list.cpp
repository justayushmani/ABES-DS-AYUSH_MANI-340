#include <iostream>
#include <cstdlib> 
using namespace std;

struct Node {
    int data;
    Node* next;
};


void insertNode(Node*& head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
   
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


void displayList(Node* head) {
    cout << "Linked List: ";
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
  
}

int main() {
    Node* head = nullptr;

    insertNode(head, 10);
    
    displayList(head);

    Node* temp = head;
    while (temp != nullptr) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }

    return 0;
}
