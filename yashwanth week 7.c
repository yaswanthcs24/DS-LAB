#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev,*next;
};
struct node *head=NULL;
void create(int val){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=val;
    newNode->prev=newNode->next=NULL;
    if(head==NULL){
        head=newNode;
        return;
    }
    struct node *temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newNode;
    newNode->prev=temp;
}
void insertLeft(int key,int val){
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    struct node *temp=head;
    while(temp!=NULL&&temp->data!=key)
        temp=temp->next;
    if(temp==NULL){
        printf("Key not found\n");
        return;
    }
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=val;
    newNode->next=temp;
    newNode->prev=temp->prev;
    if(temp->prev!=NULL){
        temp->prev->next=newNode;
    }
    else
        head=newNode;
    temp->prev=newNode;
}
void delete(int key){
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    struct node *temp=head;
    while(temp!=NULL&&temp->data!=key)
        temp=temp->next;
    if(temp==NULL){
        printf("Value not found\n");
        return;
    }
    if(temp->prev!=NULL)
        temp->prev->next=temp->next;
    else
        head=temp->next;
    if(temp->next!=NULL)
        temp->next->prev=temp->prev;
    free(temp);
}
void display(){
    struct node *temp=head;
    if(temp->next==NULL){
        printf("List is empty\n");
        return;
    }
    printf("lIST:");
    while(temp!=NULL){
        printf("%d-> ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main(){
    int ch,val,key;
    while(1){
        printf("\n1.Create  2.InsertLeft  3.Delete  4.Display  5.Exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1: scanf("%d",&val); create(val); break;
            case 2: scanf("%d%d",&key,&val); insertLeft(key,val); break;
            case 3: scanf("%d",&key); delete(key); break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("Invalid\n");
        }
    }
}
