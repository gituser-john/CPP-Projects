#include<stdio.h>
#include<stdlib.h>

struct node{
    int co;
    int ex;
    struct node* next;
    struct node* prev;
};

struct node* create_node(int coef,int exp){
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr->co = coef;
    ptr->ex = exp;
    ptr->next = NULL;
    ptr->prev = NULL;
    return ptr;
}

struct node* insert(struct node* head, struct node* new_ptr) {
    if (head == NULL) {  
        new_ptr->prev = NULL;
        new_ptr->next = NULL;
        return new_ptr;
    }

    struct node* ptr = head;
    
    
    if (new_ptr->ex > head->ex) {
        new_ptr->next = head;
        head->prev = new_ptr;
        new_ptr->prev = NULL;
        return new_ptr;
    }
    
    
    while (ptr->next != NULL && ptr->next->ex >= new_ptr->ex) {
        ptr = ptr->next;
    }

    
    if (ptr->ex == new_ptr->ex) {
        ptr->co += new_ptr->co;
    }
    
    else if (ptr->next == NULL || ptr->next->ex < new_ptr->ex) {
        new_ptr->next = ptr->next;
        if (ptr->next != NULL) {
            ptr->next->prev = new_ptr;
        }
        ptr->next = new_ptr;
        new_ptr->prev = ptr;
    }

    return head;
}

struct node* mult(struct node* head1,struct node* head2){
    int coef=0,exp=0;
    struct node* ptr1=head1,*ptr2 = head2,*temp = NULL,*head = NULL;
    while(ptr1!=NULL){
        ptr2 = head2;
        while(ptr2!=NULL){
            coef = ptr1->co*ptr2->co;
            exp = ptr1->ex+ptr2->ex;
            temp = create_node(coef,exp);
            head = insert(head,temp);
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return head;
}

void display(struct node *head){
    struct node *ptr = head;
    while(ptr->next!=NULL){
        printf("%dx^%d+",ptr->co,ptr->ex);
        ptr = ptr->next;
    }
    printf("%dx^%d \n",ptr->co,ptr->ex);
}

int main(){
    int n,coef,exp;
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    struct node *head3 = NULL;

    struct node *temp = NULL;

    printf("Enter number of elements in expression 1");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter coeff and exp");
        scanf("%d %d",&coef,&exp);
        temp = create_node(coef,exp);
        head1=insert(head1,temp);
    }
    printf("Enter number of elements in expression 2");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter coeff and exp");
        scanf("%d %d",&coef,&exp);
        temp = create_node(coef,exp);
        head2=insert(head2,temp);
    }
    head3 = mult(head1,head2);
    printf("Exp 1 is :\n");
    display(head1);
    printf("Exp 2 is :\n");
    display(head2);
    printf("Exp 3 is :\n");
    display(head3);
}