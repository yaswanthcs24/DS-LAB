#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *stackHead = NULL;
struct node *queueHead = NULL;
void insertFront(struct node **head, int value) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}
void insertEnd(struct node **head, int value) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    if (*head == NULL) *head = newNode;
    else {
        struct node *temp = *head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }
}
void deleteFront(struct node **head) {
    if (*head == NULL) return;
    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);
}
void display(struct node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
int main() {
    insertFront(&stackHead, 10);
    insertFront(&stackHead, 20);
    insertFront(&stackHead, 30);
    printf("Stack after pushes: ");
    display(stackHead);
    deleteFront(&stackHead);
    printf("Stack after pop: ");
    display(stackHead);
    insertEnd(&queueHead, 1);
    insertEnd(&queueHead, 2);
    insertEnd(&queueHead, 3);
    printf("Queue after enqueues: ");
    display(queueHead);
    deleteFront(&queueHead);
    printf("Queue after dequeue: ");
    display(queueHead);
    return 0;
}

