#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;
Node *head = NULL;
void insert_start(int n){
    Node *ptr2 = (Node *)malloc(sizeof(Node));
    Node *ptr = head;
    ptr2->prev = NULL;
    ptr2->data = n;
    if(head==NULL){
        ptr2->next = NULL;
        head = ptr2;
        return;
    }
    ptr2->next = ptr;
    head = ptr2;
    ptr->prev = ptr2;
}
void insert_end(int n){
    Node *ptr2 = (Node *)malloc(sizeof(Node));
    Node *ptr = head;
    ptr2->data = n;
    ptr2->next = NULL;
    if(ptr==NULL){
        head = ptr2;
        ptr->prev = NULL;
    }
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    ptr->next = ptr2;
    ptr2->prev = ptr;
}
void insert_between(int n,int m){
    Node *ptr2 = (Node *)malloc(sizeof(Node));
    Node *ptr = head;
    ptr2->data = n;
    if(ptr==NULL){
        ptr2->next = NULL;
        ptr2->prev = NULL;
        ptr2= head;
    }
    while(ptr->next!=NULL && ptr->data!=m){
        ptr = ptr->next;
    }
    if(ptr->data==m){
        ptr2->next = ptr->next;
        ptr->next = ptr2;
        ptr2->prev = ptr;
        ptr = ptr->next;
        ptr->prev = ptr2;
    }
    else{
        printf("element not found");
    }
}
void delete_start(){
    Node *ptr = head, *ptr2;
    if(head==NULL){
        printf("empty list");
    }
    else if(ptr->next==NULL){
        head = NULL;
        free(ptr);
        printf("first element only available to be deleted");
    }
    else{
        head = ptr->next;
        head->prev = NULL;
        printf("%d is deleted from start", ptr->data);
        free(ptr);
    }
    
}
void delete_end(){
    Node *ptr = head, *ptr2;
    if (head == NULL)
    {
        printf("empty list");
    }
    else if (ptr->next == NULL)
    {
        head = NULL;
        free(ptr);
        printf("first element only available to be deleted");
    }
    else{
        while(ptr->next!=NULL){
            ptr2 = ptr;
            ptr = ptr->next;
            
        }
        ptr2->next = NULL;
        printf("%d is deleted from end", ptr->data);
        free(ptr);
    }
    
}
void delete_node(int n){
    Node *ptr = head, *ptr2;
    if (head == NULL)
    {
        printf("empty list");
    }
    else if(ptr->data==n){
        delete_start();
    }
    else{
        while(ptr->next!=NULL && ptr->data!=n){
            ptr = ptr->next;
        }
        if(ptr->next==NULL){
            delete_end();
        }
        else if(ptr->data==n){
            ptr2 = ptr->prev;
            ptr2->next = ptr->next;
            ptr2 = ptr2->next;
            ptr2->prev = ptr->prev;
            printf("%d is deleted ", ptr->data);
            free(ptr);
        }
        else{
            printf("element not found");
        }
    }
}
void display(){
    Node *temp = head;
    if(head==NULL){
        printf("list empty");
    }
    else{
        while(temp!=NULL){
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
    }
}
int main()
{
    int choice, key, value;
    printf("\t \t \t Menu \t \t \t \n \n1.INSERT AT THE BEGINING\n2.DISPLAY\n3.INSERT AT THE END \n4.INSERT AFTER SPECIFIC NODE\n5.DELETE AT THE START\n6.DELETE AT THE END\n7.DELETE A SPECIFIC NODE\n8.EXIT\n");

    do
    {
        printf("Enter your choice(1-9):");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data of node to be inserted");
            scanf("%d", &value);
            insert_start(value);
            break;
        case 2:
            display();
            break;
        case 3:
            printf("Enter data of node to be inserted");
            scanf("%d", &value);
            insert_end(value);
            break;
        case 4:
            printf("Enter the key after which the node is inserted");
            scanf("%d", &key);
            printf("Enter data of node to be inserted");
            scanf("%d", &value);
            insert_between(value, key);
            break;
        case 5:
            delete_start();
            break;
        case 6:
            delete_end();
            break;
        case 7:
            printf("Enter the key where the node be deleted");
            scanf("%d", &key);
            delete_node(key);

            break;
        case 8:
            printf("Exiting Program.....");
            break;
        default:
            printf("Invalid choice entered.");
            break;
        }
    } while (choice != 8);
    return 0;
}
