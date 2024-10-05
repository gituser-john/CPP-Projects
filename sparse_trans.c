#include<stdio.h>
void mat_def(int a[][3],int r,int c,int n)
{
    a[0][0]=r;
    a[0][1]=c;
    a[0][2]=n;
    for(int i=1;i<n+1;++i)
    {
        printf("Enter row : ");
        scanf("%d",&a[i][0]);
        printf("Enter coloumn : ");
        scanf("%d",&a[i][1]);
        printf("Enter Element %d : ",i);
        scanf("%d",&a[i][2]);
    }
}
void mat_dis(int a[][3])
{
    for(int i=0;i<a[0][2]+1;++i)
    {
        printf("%d  ",a[i][0]);
        printf("%d  ",a[i][1]);
        printf("%d  \n",a[i][2]);
    }
}
void sparse_trans(int a[][3],int b[][3])
{
    int k=1;
    b[0][0]=a[0][1];
    b[0][1]=a[0][0];
    b[0][2]=a[0][2];
    for(int i=0;i<a[0][1];++i)
    {
        for(int j=0;j<a[0][2]+1;++j)
        {
            if(a[j][1]==i)
            {
                b[k][0]=a[j][1];
                b[k][1]=a[j][0];
                b[k][2]=a[j][2];
                ++k;   
            }
        }
    }
}
void main()
{
    int r,c,n;
    printf("Enter Matrix\n");
    printf("Number of Rows : ");
    scanf("%d",&r);
    printf("Number of Coloumns : ");
    scanf("%d",&c);
    printf("Number of Non Zero Elements : ");
    scanf("%d",&n);
    int a[n+1][3],b[n+1][3];;
    mat_def(a,r,c,n);
    sparse_trans(a,b);
    printf("Transpose Matrix\n");
    mat_dis(b);
}