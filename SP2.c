#include <stdio.h>

int main(){
    int row,col,count=0;
    int Tuple[100][3];
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
            if (Matrix[i][j]!=0){
                Tuple[count+1][0]=i;
                Tuple[count+1][1]=j;
                Tuple[count+1][2]=Matrix[i][j];
                count++;
            }
        }
    }
    Tuple[0][0]=row;
    Tuple[0][1]=col;
    Tuple[0][2]=count;
    printf("Matrix is : \nRow\tCol\tElement\n");
    for(int i=0;i<=count;i++){
        printf("%d\t%d\t%d\n",Tuple[i][0],Tuple[i][1],Tuple[i][2]);
    }
    return 0;
}