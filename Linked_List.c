#include<stdio.h>
#include<stdlib.h>

struct node{
        int data;
        struct node *next;
};
struct node *head=NULL;

void ins_front(int n){
        struct node *ptr = (struct node*)malloc(sizeof(struct node));
        ptr->data = n;
        ptr->next = head;
        head=ptr;
    }

void ins_end(int n){
        struct node *ptr2 = (struct node*)malloc(sizeof(struct node));
        ptr2->data = n;
        ptr2->next = NULL;
        struct node *ptr=head;
        if(ptr==NULL){
            head=ptr2;
        }
        else{
            while (ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=ptr2;
        }
}

void ins_btw(int n,int m){
        struct node *ptr2 = (struct node*)malloc(sizeof(struct node));
        ptr2->data = n;
        struct node *ptr=head;
        if(ptr==NULL){
            ptr2->next=NULL;
            head=ptr2;
        }
        while(ptr!=NULL && ptr->data!=m){
            ptr=ptr->next;
        }
        if(ptr!=NULL){
            ptr2->next=ptr->next;
            ptr->next=ptr2;
        }
        else if(ptr->next==NULL && ptr->data==m){
            ptr->next=ptr2;
            ptr2->next=NULL;
        }
        else{
            printf("Element not found");
        }
}

void del_head(){
        struct node *ptr=head;
        if(ptr==NULL){
            printf("List is Empty");
        }
        else{
            head=ptr->next;
            free(ptr);
        }
    }

void del_end(){
        struct node *ptr=head,*ptr2;
        if(ptr==NULL){
            printf("list Empty");
        }
        else if(ptr->next==NULL){
            head=NULL;
            free(ptr);
        }
        else{
            while(ptr->next!=NULL){
                ptr2=ptr;
                ptr=ptr->next;
            }
            ptr2->next=NULL;
            free(ptr);
        }
}

void del_btw(int m){
        struct node *ptr=head,*ptr2;
        if (ptr==NULL){
            printf("List is Empty");
        }
        else{
            while(ptr->next!=NULL && ptr->data!=m){
                ptr2=ptr;
                ptr=ptr->next;
            }
            if(ptr->next!=NULL){
                ptr2->next=ptr->next;
                free(ptr);
            }
            else{
                printf("Element not found");
            }
        }
}

void display(){
        struct node *ptr=head;
        if(ptr==NULL){
            printf("List Empty");
        }
        else{
            while(ptr->next!=NULL){
                printf("%d, ",ptr->data);
                ptr=ptr->next;
            }
            printf("%d, ",ptr->data);
        }
}

int main(){
    int a,b,c,d,q=0;
    do{
        printf("Enter value : \n1.Insertion at Front\n2.Insertion at End\n3.Insertion in Between\n4.Delete at front\n5.Delete at end\n6.Delete in between\n7.Display List\n8.Exit\n");
        scanf("%d",&a);
        switch (a)
        {
        case 1:
            printf("Enter value : ");
            scanf("%d",&b);
            ins_front(b);
            break;
        case 2:
            printf("Enter value : ");
            scanf("%d",&b);
            ins_end(b);
            break;
        case 3:
            printf("Enter value : ");
            scanf("%d",&b);
            printf("Enter value at which to be inserted :");
            scanf("%d",&c);
            ins_btw(b,c);
            break;
        case 4:
            del_head();
            break;
        case 5:
            del_end();
            break;
        case 6:
            printf("Enter value to be deleted");
            scanf("%d",&d);
            del_btw(d);
            break;
        case 7:
            display();
            break;
        case 8:
            q=4;
        default:
            printf("Enter valid choice");
            break;
        }
    }
    while(q!=4);
    return 0;
}