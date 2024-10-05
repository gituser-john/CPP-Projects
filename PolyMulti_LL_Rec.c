#include<stdio.h>
#include<stdlib.h>
//insertion at head when there are more than 1 elements not corrected/implemented.
struct node{
    int co;
    int ex;
    struct node* next;
    struct node* prev;
};

struct node* insert(struct node* head,struct node* ptr,struct node* new_ptr){
    if(head == NULL){
        new_ptr->prev = NULL;
        new_ptr->next = NULL;
        head = new_ptr;
        return head;
    }
    else if(ptr->next==NULL){
        if(ptr->ex>new_ptr->ex){
            ptr->next = new_ptr;
            new_ptr->next = NULL;
            new_ptr->prev = ptr;
            return head;
        }
        else if(ptr->ex == new_ptr->ex){
            ptr->co += new_ptr->co;
            return head;
        }
        else{
            ptr->prev = new_ptr;
            new_ptr->next = ptr;
            new_ptr->prev = NULL;
            head = new_ptr;
            return head;
        }
    }
    else if(ptr->next->ex == new_ptr->ex){
        ptr->next->co += new_ptr->co;
        return head;
    }
    else if(ptr->next->ex<new_ptr->ex){
        ptr->next->prev = new_ptr;
        new_ptr->next = ptr->next;
        new_ptr->prev = ptr;
        ptr->next = new_ptr;
        return head;
    }
    else if(ptr->ex>new_ptr->ex){
        if(ptr->next!=NULL){
            insert(head,ptr->next,new_ptr);
        }
    }
}


void display(struct node *head){
    struct node *ptr = head;
    while(ptr->next!=NULL){
        printf("%dx^%d ",ptr->co,ptr->ex);
        ptr = ptr->next;
    }
    printf("%dx^%d ",ptr->co,ptr->ex);
}

int main(){
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    struct node *head3 = NULL;
    struct node *new_ptr1 = (struct node*)malloc(sizeof(struct node));
    new_ptr1->co = 3;
    new_ptr1->ex = 0;
    head1 = insert(head1,head1,new_ptr1);
    struct node *new_ptr2 = (struct node*)malloc(sizeof(struct node));
    new_ptr2->co = 5;
    new_ptr2->ex = 7;
    head1 = insert(head1,head1,new_ptr2);
    struct node *new_ptr3 = (struct node*)malloc(sizeof(struct node));
    new_ptr3->co = 3;
    new_ptr3->ex = 3;
    head1 = insert(head1,head1,new_ptr3);
    struct node *new_ptr4 = (struct node*)malloc(sizeof(struct node));
    new_ptr4->co = 5;
    new_ptr4->ex = 10;
    head1 = insert(head1,head1,new_ptr4);
    display(head1);
}