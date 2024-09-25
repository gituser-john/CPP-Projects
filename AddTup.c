#include<stdio.h>

int main(){
    int row,col,tup1[100][3],tup2[100][3],tupSum[100][3],nonZeroCount1,nonZeroCount2;

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

printf("Enter numberof rows : ");
    scanf("%d",&row);
    printf("Enter number of coloumns : ");
    scanf("%d",&col);

    printf("Enter number of non zero values : ");
    scanf("%d",&nonZeroCount2);

    tup2[0][0]=row;
    tup2[0][1]=col;
    tup2[0][2]=nonZeroCount2;

    for(int i=1;i<=nonZeroCount2;i++){
        printf("Enter values of row col and element : ");
        scanf("%d %d %d",&tup2[i][0],&tup2[i][1],&tup2[i][2]);
    }

    int i=1,j=1,k=1;
    tupSum[0][0]=tup1[0][0];
    tupSum[0][1]=tup1[0][1];
    while(i<=nonZeroCount1 && j<=nonZeroCount2){
        if(tup1[0][0]!=tup2[0][0] || tup1[0][1]!=tup2[0][1]){
            printf("Row and coloumns do not match");
            return 0;
        }
        
        
        if(tup1[i][0]==tup2[j][0] && tup1[i][1]==tup2[j][1]){
            tupSum[k][0]=tup1[i][0];
            tupSum[k][1]=tup1[i][1];
            tupSum[k][2]=tup1[i][2]+tup2[j][2];
            i++;
            j++;
            k++;
        }
        else if (tup1[i][0]==tup2[j][0])
        {
            if(tup1[i][1]>tup2[j][1]){
                tupSum[k][0]=tup2[j][0];
                tupSum[k][1]=tup2[j][1];
                tupSum[k][2]=tup2[j][2];
                j++;
                k++;
            }
            else{
                tupSum[k][0]=tup1[i][0];
                tupSum[k][1]=tup1[i][1];
                tupSum[k][2]=tup1[i][2];
                i++;
                k++;
            }
        }
        else{
            if(tup1[i][0]<tup2[j][0]){
                tupSum[k][0]=tup1[i][0];
                tupSum[k][1]=tup1[i][1];
                tupSum[k][2]=tup1[i][2];
                i++;
                k++;
            }
            else if (tup1[i][0]>tup2[j][0])
            {
                tupSum[k][0]=tup2[j][0];
                tupSum[k][1]=tup2[j][1];
                tupSum[k][2]=tup2[j][2];
                j++;
                k++;
            }
            
        }
        
    }

    while(i <= nonZeroCount1) {
        tupSum[k][0] = tup1[i][0];
        tupSum[k][1] = tup1[i][1];
        tupSum[k][2] = tup1[i][2];
        i++; k++;
    }

    while(j <= nonZeroCount2) {
        tupSum[k][0] = tup2[j][0];
        tupSum[k][1] = tup2[j][1];
        tupSum[k][2] = tup2[j][2];
        j++; k++;
    }
    /*
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
    */
    tupSum[0][2]=k;
    

    printf("Row Column Element\n");
    for(int i=0;i<k;i++){
        printf("%d  %d  %d\n",tupSum[i][0],tupSum[i][1],tupSum[i][2]);
    }
    
    return 0;
}