#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

void insert_begin(int val){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = val;
    if(head==NULL){
        ptr->prev=ptr;
        ptr->next=ptr;
        head=ptr;
    }
    else{
        struct Node* ptr2 = head->prev;
        ptr2->next = ptr;
        ptr->prev = ptr2;
        ptr->next = head;
        head = ptr;
    }
}

void insert_end(int val){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = val;
    if(head==NULL){
        head=ptr;
        ptr->prev = ptr;
        ptr->next = ptr;
        return;
    }
    struct Node* ptr2 = head->prev;
    ptr2->next = ptr;
    ptr->prev = ptr2;
    ptr->next = head;
    head->prev = ptr;
}

void insert_val(int key,int val){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = val;
    if(head==NULL){
        printf("No elements found\n");
        return;
    }
    struct Node* ptr2 = head;
    while(ptr2->data!=key && ptr2->next!=head){
        ptr2=ptr2->next;
    }
    if(ptr2->data==key && ptr2->next==head){
        insert_end(val);
    }
    else if(ptr2->data==key && ptr2==head){
        insert_begin(val);
    }
    else if(ptr2->data==key){
        ptr->next = ptr2->next;
        ptr->prev = ptr2;
        ptr->next->prev = ptr;
        ptr2->next = ptr;
    }
    else{
        printf("Key not found\n");
    }
    
}

void del_begin(){
    struct Node* ptr = head;
    if(head==NULL){
        printf("No elements in list");
        return;
    }
    if(ptr->next==ptr){
        head=NULL;
        printf("value %d removed \n",ptr->data);
        free(ptr);
        return;
    }
    ptr = head->prev;
    ptr->next = head->next;
    head->next->prev = ptr;
    ptr = head;
    head = head->next;
    printf("value %d removed \n",ptr->data);
    free(ptr);
    
}

void del_end(){
    struct Node* ptr = head,*ptr2;
    if(ptr->next==ptr){
        head=NULL;
        printf("value %d removed \n",ptr->data);
        free(ptr);
        return;
    }
    ptr = head->prev;
    ptr2 = head->prev->prev;
    ptr2->next = head;
    head->prev = ptr2;
    printf("value %d removed \n",ptr->data);
    free(ptr);
}

void del_key(int key){
    struct Node* ptr = head,*ptr2;
    while(ptr->data!=key && ptr->next!=head){
        ptr2 = ptr;
        ptr = ptr->next;
    }
    if(ptr->data == key && head->next == head){
        head = NULL;
        printf("value %d removed \n",ptr->data);
        free(ptr);
    }
    else if(ptr==head){
        del_begin();
    }
    else if(ptr->data==key){
        ptr2->next = ptr->next;
        ptr->next->prev = ptr2;
        printf("value %d removed \n",ptr->data);
        free(ptr);
    }
    else{
        printf("Key not found\n");
    }
}

void display(){
    struct Node* ptr = head;
    if(head==NULL){
        printf("No Elements in LL\n");
        return;
    }
    while(ptr->next!=head){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("%d\n",ptr->data);
}

/*
void display(struct Node* ptr){
    
    if(ptr==NULL){
        return;
    }
    display(ptr->next);
    printf("%d ",ptr->data);
}
*/
int main(){
    int val,key,choice;
    while(choice!=8){
        printf("Enter choice :\n1.Insert begin\n2.Insert End\n3.Insert Key\n4.Del Front\n5.Del End\n6.Del Key\n7.Display\n8.Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter value\n");
                scanf("%d",&val);
                insert_begin(val);
                break;
            case 2:
                printf("Enter value\n");
                scanf("%d",&val);
                insert_end(val);
                break;
            case 3:
                printf("Enter key and val \n");
                scanf("%d %d",&key,&val);
                insert_val(key,val);
                break;
            case 4:
                printf("Deleting from Front\n");
                del_begin();
                break;
            case 5:
                printf("Deleting value from End\n");
                del_end();
                break;
            case 6:
                printf("Enter key for deletion\n");
                scanf("%d",&key);
                del_key(key);
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Exiting..");
                break;
            default :
                printf("Enter valid Input\n");
                break;
        }
    }
}