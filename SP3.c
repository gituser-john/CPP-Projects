#include <stdio.h>

int main(){
    int row,col,count1,count2,count3;
    printf("Enter number of row,col of Tuple : ");
    scanf("%d %d",&row,&col);
    printf("Enter number of non zero for Tuple 1 and 2");
    scanf("%d %d",&count1,&count2);
    int Tuple1[count1][3],Tuple2[count2][3],Tuple3[count3][3];
    Tuple1[0][0]=Tuple2[0][0]=Tuple3[0][0]=row;
    Tuple1[0][1]=Tuple2[0][1]=Tuple3[0][1]=col;
    Tuple1[0][2]=count1;
    Tuple2[0][2]=count2;
    int total=row*col;
    int i=1,j=1,k=1;
    for(int i=1;i<=count1;i++){
        printf("enter value for tup1 : ");
        scanf("%d %d %d",&Tuple1[i][0],&Tuple1[i][1],&Tuple1[i][2]);
    }
    for(int i=1;i<=count2;i++){
        printf("enter value for tup1 : ");
        scanf("%d %d %d",&Tuple2[i][0],&Tuple2[i][1],&Tuple2[i][2]);
    }
    while(i<=count1 && j<=count2){
        if (Tuple1[i][0]==Tuple2[j][0]){
            if (Tuple1[i][1]==Tuple2[j][1]){
                Tuple3[k][0]=Tuple1[i][0];
                Tuple3[k][1]=Tuple1[i][1];
                Tuple3[k][2]=Tuple1[i][2]+Tuple2[j][2];
                i++,j++,k++;
            }
            else if(Tuple1[i][1]>Tuple2[j][1]){
                Tuple3[k][0]=Tuple2[j][0];
                Tuple3[k][1]=Tuple2[j][1];
                Tuple3[k][2]=Tuple2[j][2];
                j++,k++;
            }
            else{
                Tuple3[k][0]=Tuple1[i][0];
                Tuple3[k][1]=Tuple1[i][1];
                Tuple3[k][2]=Tuple1[i][2];
                i++,k++;
            }
        }
        else if(Tuple1[i][0]<Tuple2[j][0]){
            Tuple3[k][0]=Tuple1[i][0];
            Tuple3[k][1]=Tuple1[i][1];
            Tuple3[k][2]=Tuple1[i][2];
            i++,k++;
        }
        else{
            Tuple3[k][0]=Tuple2[j][0];
            Tuple3[k][1]=Tuple2[j][1];
            Tuple3[k][2]=Tuple2[j][2];
            j++,k++;
        }
    }
    while(i<count1){
        Tuple3[k][0]=Tuple1[i][0];
        Tuple3[k][1]=Tuple1[i][1];
        Tuple3[k][2]=Tuple1[i][2];
        i++,k++;
    }
    while(j<count2){
        Tuple3[k][0]=Tuple2[j][0];
        Tuple3[k][1]=Tuple2[j][1];
        Tuple3[k][2]=Tuple2[j][2];
        j++,k++;
    }
    count3=k-1;
    Tuple3[0][2]=count3;
    printf("Matrix is : \nRow\tCol\tElement\n");
    for(int i=0;i<=count3;i++){
        printf("%d\t%d\t%d\n",Tuple3[i][0],Tuple3[i][1],Tuple3[i][2]);
    }
    return 0;
}