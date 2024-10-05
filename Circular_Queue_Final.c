#include<stdio.h>
#define size 5
int cQueue[5];
int front=-1,rear=-1;

int isFull(){
    if ((rear+1)%size==front){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(){
    if(rear==-1 && front==-1){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(int n){
    if(isFull()){
        printf("Queue is Full,Overflow!\n");
        return;
    }
    if(front==-1){
        front=0;
    }
    rear=(rear+1)%size;
    cQueue[rear]=n;
    printf("%d added to Queue\n",n);
    return;
}

void dequeue(){
    if(isEmpty()){
        printf("Queue is Empty,Underflow!\n");
        return;
    }

    if(front==rear){
        int temp=cQueue[front];
        printf("%d removed from the Queue\n",temp);
        front=-1,rear=-1;
        printf("Queue Empty\n");
        return;
    }
    int temp=cQueue[front];
    printf("%d removed from the Queue\n",temp);
    front=(front+1)%size;
    return;
}

void display(){
    if(isEmpty()){
        printf("Queue Empty!\n");
        return;
    }
    int a=front,b=rear;
    printf("The queue is : ");
    for(int i=front;i!=rear;i=(i+1)%size){
        printf("%d ",cQueue[i]);
    }
    printf("%d\n",cQueue[rear]);
}

void peek() {
    if (isEmpty()) {
        printf("Queue is Empty!\n");
    } else {
        printf("Front element is: %d\n", cQueue[front]);
    }
}
int main(){
    int c=1;
    while (c!=0){
        printf("***************CIRCULAR QUEUE**************\n");
        printf("Enter \n1.Enqueue\n2.Dequeue\n3.Display\n4.Peek\n5.Exit\n");
        int a;
        scanf("%d",&a);
        switch (a){
            case 1:
                printf("Enter Value : ");
                int b;
                scanf("%d",&b);
                enqueue(b);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                c=0;
                break;
            default:
                printf("Please enter valid number\n");
                break;
        }
    }
return 0;
}