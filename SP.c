#include <stdio.h>

int main(){
    int row,col,count=0;
    float check=0.0;
    printf("Enter number of rows and coloumns : ");
    scanf("%d %d",&row,&col);
    int Matrix[row][col];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("Enter value at Matrix[%d][%d] ",i,j);
            scanf("%d",&Matrix[i][j]);
        }
    }
    int total=row*col;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if (Matrix[i][j]==0){
                count++;
            }
        }
    }
    check=((float)count/total)*100;
    if(count>(total/2)){
        printf("Matrix is Sparse,percentage is : %f",check);
    }
    else{
        printf("Matrix is not Sparse");
    }
    return 0;
}