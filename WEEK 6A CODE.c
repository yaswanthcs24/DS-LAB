#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *head1 = NULL;
struct node *head2 = NULL;
struct node* createNode(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertEnd(struct node **head, int data) {
    struct node *newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}
void display(struct node *head) {
    if (head == NULL) {
        printf("List empty!\n");
        return;
    }
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void sortList(struct node *head) {
    if (head == NULL || head->next == NULL) {
        printf("List too short to sort!\n");
        return;
    }
    struct node *i, *j;
    int temp;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("List sorted.\n");
}
struct node* reverseList(struct node *head) {
    struct node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    printf("List reversed.\n");
    return prev;
}
void concatenateLists() {
    if (head1 == NULL) {
        head1 = head2;
        head2 = NULL;
        printf("Concatenated.\n");
        return;
    }
    struct node *temp = head1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head2;
    head2 = NULL;
    printf("Concatenated.\n");
}
int main() {
    int choice, val;
    while (1) {
        printf("\nMenu:\n"
               "1.Insert L1   2.Insert L2   3.Display L1   4.Display L2\n"
               "5.Sort L1     6.Reverse L1  7.Concat L2->L1 8.Exit\n"
               "Choice: ");
        if (scanf("%d", &choice) != 1) return 0;
        if (choice == 1 || choice == 2) {
            printf("Value: ");
            if (scanf("%d", &val) != 1) return 0;
        }
        switch (choice) {
            case 1: insertEnd(&head1, val); break;
            case 2: insertEnd(&head2, val); break;
            case 3: display(head1); break;
            case 4: display(head2); break;
            case 5: sortList(head1); break;
            case 6: head1 = reverseList(head1); break;
            case 7: concatenateLists(); break;
            case 8: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
