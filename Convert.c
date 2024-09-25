#include<stdio.h>

int main(){
    int row,col,mat[10][10],tup[100][3],nonZero_count=0;

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
            if(mat[i][j]!=0){
                tup[nonZero_count+1][0]=i;
                tup[nonZero_count+1][1]=j;
                tup[nonZero_count+1][2]=mat[i][j];
                nonZero_count++;
            }
        }
    }

    tup[0][0]=row;
    tup[0][1]=col;
    tup[0][2]=nonZero_count;

    printf("Row Column Element\n");
    for(int i=0;i<=nonZero_count;i++){
        printf("%d  %d  %d\n",tup[i][0],tup[i][1],tup[i][2]);
    }
    
    return 0;
}