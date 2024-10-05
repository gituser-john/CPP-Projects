#include<stdio.h>
#include<math.h>
void push(int s[],int n,int *t,int max)
{
    if (*t==max-1)
    {
        printf("Stack full");
    }
    else
    {
        ++*t;
        s[*t]=n;
    }
}
int pop(int s[],int *t)
{
    if(*t==-1)
    {
        return '\0';
    }
    else
    {
        int temp=s[*t];
        --*t;
        return temp;
    }
}
int priority(char c)
{
    switch(c)
    {
        case '+':case '-':
            return 1;
            break;
        case '*':case '/':
            return 2;
            break;
        case '^':
            return 3;
            break;
        case '(':
            return 4;
            break;
        default:
            return 0;
            break;
    }
}
void main()
{
    char pos[50];
    int stack[50],val,top=-1,len=0,max=50;
    printf("Postfix Expression : ");
    scanf("%s",&pos);
    while(pos[len]!='\0')
    {
        ++len;
    }
    for(int i=0;i<len;++i)
    {
        if(priority(pos[i])==0)
        {
            int n;
            printf("Enter Value of %c : ",pos[i]);
            scanf("%d",&n);
            push(stack,n,&top,max);
        }
        else if(3>=priority(pos[i])>=1)
        {
            int n1,n2;
            n2=pop(stack,&top);
            n1=pop(stack,&top);
            switch(pos[i])
            {
                case '+':
                    push(stack,n1+n2,&top,max);
                    break;
                case '-':
                    push(stack,n1-n2,&top,max);
                    break;
                case '*':
                    push(stack,n1*n2,&top,max);
                    break;
                case '/':
                    push(stack,n1/n2,&top,max);
                    break;
                case '^':
                    push(stack,pow(n1,n2),&top,max);
                    break;
                default:
                    break;
            }
        }
    }
    printf("Result : %d",pop(stack,&top));
}