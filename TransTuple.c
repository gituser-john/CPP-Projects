#include<stdio.h>

int main(){
    int row,col,tup1[100][3],tup2[100][3],nonZeroCount1,nonZeroCount2,k=1;

    printf("Enter numberof rows : ");
    scanf("%d",&row);
    printf("Enter number of coloumns : ");
    scanf("%d",&col);

    printf("Enter number of non zero values : ");
    scanf("%d",&nonZeroCount1);

    tup1[0][0]=row;
    tup1[0][1]=col;
    tup1[0][2]=nonZeroCount1;

    for(int i=1;i<=nonZeroCount1;i++){
        printf("Enter values of row col and element : ");
        scanf("%d %d %d",&tup1[i][0],&tup1[i][1],&tup1[i][2]);
    }

    tup2[0][1]=tup1[0][0];
    tup2[0][0]=tup1[0][1];
    tup2[0][2]=tup1[0][2];

    for(int i=0;i<tup1[0][0];i++){
        for(int j=1;j<=tup1[0][2];j++){
            if(tup1[j][1]==i){
                tup2[k][0]=tup1[j][1];
                tup2[k][1]=tup1[j][0];
                tup2[k][2]=tup1[j][2];
                k++;
            }
        }
    }

    printf("Row Column Element\n");
    for(int i=0;i<k;i++){
        printf("%d  %d  %d\n",tup2[i][0],tup2[i][1],tup2[i][2]);
    }
    
    return 0;
}