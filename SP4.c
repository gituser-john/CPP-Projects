#include <stdio.h>

int main(){
    int row,col,count;
    printf("Enter number of row,col of Tuple : ");
    scanf("%d %d %d",&row,&col,&count);
    int Tuple1[count][3],Tuple2[count][3];
    Tuple1[0][0]=row,Tuple1[0][1]=col,Tuple1[0][2]=count;
    int total=row*col;
    for(int i=1;i<=count;i++){
        printf("enter value for tup1 : ");
        scanf("%d %d %d",&Tuple1[i][0],&Tuple1[i][1],&Tuple1[i][2]);
    }
    int k=1;
    for(int i=0;i<Tuple1[0][1];i++){
        for(int j=1;j<=Tuple1[0][2];j++){
            if(Tuple1[j][1]==i){
                Tuple2[k][0]=Tuple1[j][1];
                Tuple2[k][1]=Tuple1[j][0];
                Tuple2[k][2]=Tuple1[j][2];
                k++;
            }
        }
    }
    Tuple2[0][0]=col;
    Tuple2[0][1]=row;
    Tuple2[0][2]=k-1;

    printf("Matrix is : \nRow\tCol\tElement\n");
    for(int i=0;i<k;i++){
        printf("%d\t%d\t%d\n",Tuple2[i][0],Tuple2[i][1],Tuple2[i][2]);
    }
    return 0;
}