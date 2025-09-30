#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;

struct node* getNode(int value) {
    struct node* q = (struct node*)malloc(sizeof(struct node));
    q->data = value;
    q->next = NULL;
    return q;
}

struct node* InsertAtBegin(struct node* start, int value) {
    struct node* newnode = getNode(value);

    if (start == NULL) {
        newnode->next = newnode;
        start = newnode;
        return start;
    }

   
    struct node* temp = start;
    while (temp->next != start) {
        temp = temp->next;

    }

    temp->next = newnode;
    newnode->next = start;
    start = newnode;

    return start;
}

// Traversal
void Traversal(struct node* start) {
    if (start == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    struct node* p = start;
    do {
        cout << p->data << " ";
        p = p->next;
    } while (p != start);

    cout << endl;
}


int main() {
    start = InsertAtBegin(start, 10);
    start = InsertAtBegin(start, 20);
    start = InsertAtBegin(start, 30);

    Traversal(start);  
    return 0;
}
