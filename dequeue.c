#include<stdio.h>
#include<stdbool.h>
void enqueuefront(int a[],int n,int *f,int *r,int len)
{
    if(*f==(*r+1)%len)
    {
        printf("Queue full\n");
    }
    else if(*f==-1)
    {
        *f=*r=0;
        a[*f]=n;
    }
    else
    {
        *f=(*f-1+len)%len;
        a[*f]=n;
    }
}
void enqueuerear(int a[],int n,int *f,int *r,int len)
{
    if(*f==(*r+1)%len)
    {
        printf("Queue full\n");
    }
    else if(*f==-1)
    {
        *f=*r=0;
        a[*r]=n;
    }
    else
    {
        *r=(*r+1+len)%len;
        a[*r]=n;
    }
}
int dequeuefront(int a[],int *f,int *r,int len)
{
    int temp;
    if(*f==-1)
    {
        printf("Queue empty\n");
        return -1;
    }
    else if(*f==*r)
    {
        temp=a[*f];
        *f=*r=-1;
        return temp;
    }
    else
    {
        temp=a[*f];
        *f=(*f+1)%len;
        return temp;
    }
}
int dequeuerear(int a[],int *f,int *r,int len)
{
    int temp;
    if(*f==-1)
    {
        printf("Queue empty\n");
        return -1;
    }
    else if(*f==*r)
    {
        temp=a[*r];
        *f=*r=-1;
        return temp;
    }
    else
    {
        temp=a[*r];
        *r=(*r-1+len)%len;
        return temp;
    }
}
int peek(int a[],int *f)
{
    if(*f==-1)
    {
        printf("Queue empty\n");
        return -1;
    }
    else
    {
        return a[*f]; 
    }
}
bool IsEmpty(int *f)
{
    return *f==-1;
}
bool IsFull(int *f,int *r,int len)
{
    return *f==(*r+1)%len;
}
void main()
{
    int len,front=-1,rear=-1;
    printf("Enter queue size : ");
    scanf("%d",&len);
    int queue[len];
    char ch;
    do
    {
        printf("Queue Operations\n1.Enqueuefront\n2.Enqueuerear\n3.Dequeuefront\n4.Dequeuerear\n5.Peek\n6.IsEmpty\n7.IsFull\n");
        int op,n;
        printf("Enter option number : ");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                printf("Enter element : ");
                scanf("%d",&n);
                enqueuefront(queue,n,&front,&rear,len);
                break;
            case 2:
                printf("Enter element : ");
                scanf("%d",&n);
                enqueuerear(queue,n,&front,&rear,len);
                break;
            case 3:
                n=dequeuefront(queue,&front,&rear,len);
                if(n!=-1)
                {
                    printf("Dequeued element : %d\n",n);
                    break;
                }
                break;
            case 4:
                n=dequeuerear(queue,&front,&rear,len);
                if(n!=-1)
                {
                    printf("Dequeued element : %d\n",n);
                    break;
                }
                break;
            case 5:
                n=peek(queue,&front);
                if(n!=-1)
                {
                    printf("Front element : %d\n",n);
                }
                break;
            case 6:
                if(IsEmpty(&front))
                {
                    printf("Queue empty\n");
                }
                else
                {
                    printf("Queue not empty\n");
                }
                break;
            case 7:
                if(IsFull(&front,&rear,len))
                {
                    printf("Queue full\n");
                }
                else
                {
                    printf("Queue not full\n");
                }
                break;
            default :
                printf("Invalid option\n");
                break;
        }
        printf("Do you want to continue (y/n) ? : ");
        scanf(" %c",&ch);
    }
    while(ch=='y');
}