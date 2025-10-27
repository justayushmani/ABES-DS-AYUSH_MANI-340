#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int countNodes(struct node *head) {
    int count = 0;
    struct node *temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

int main() {
    struct node *head = NULL, *second = NULL, *third = NULL;

    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    printf("Number of nodes in the linked list = %d\n", countNodes(head));

    return 0;
}
