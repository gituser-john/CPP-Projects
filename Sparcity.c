#include<stdio.h>

int main(){
    int row,col,mat[10][10],zero_count=0;

    printf("Enter numberof rows : ");
    scanf("%d",&row);
    printf("Enter number of coloumns : ");
    scanf("%d",&col);

    printf("Enter matrix values : ");

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("Enter value at %d row %d col",i,j);
            scanf("%d",&mat[i][j]);
        }
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(mat[i][j]==0){
                zero_count++;
            }
        }
    }
    if (zero_count>(row*col)/2){
        printf("The matrix is a sparse matrix \n");
        float x=((float)zero_count/(row*col))*100;
        printf("The Sparsity is : %f",x);
    }
    else{
        printf("Matrix is not Sparse");
    }
    return 0;
}