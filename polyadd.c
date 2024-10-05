#include<stdio.h>
void defpoly(int a[],int n)
{
    for(int i=0;i<n+1;++i)
    {
        printf("Enter x^%d coeffeicient : ",i);
        scanf("%d",&a[i]);
    }
}
void polyadd(int a[],int b[],int c[],int m,int n)
{
    int max=m>n?m:n;
    for(int i=0;i<max+1;++i)
    {
        c[i]=0;
        if(i<m+1)
        {
            c[i]+=a[i];
        }
        if(i<n+1)
        {
            c[i]+=b[i];
        }
    }
}
void display(int a[],int n)
{
    printf("Added polynomial : ");
    for(int i=0;i<n+1;++i)
    {
        printf("%dx^%d",a[i],i);
        if(i<n)
        {
            printf("  +  ");
        }
    }
    printf("\n");
}
void main()
{
    int m,n,max;
    printf("Enter degree of polynomial 1 and 2 : ");
    scanf("%d%d",&m,&n);
    max=m>n?m:n;
    int a[m+1],b[n+1],c[max+1];
    printf("Enter polynomial 1\n");
    defpoly(a,m);
    printf("Enter polynomial 2\n");
    defpoly(b,n);
    polyadd(a,b,c,m,n);
    display(c,max);
}