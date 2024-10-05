    #include <stdio.h>

    struct Poly{
        int coeff;
        int exp;
    };

    void Init(int count,struct Poly* p1){
        for(int i=0;i<count;i++){
            printf("Enter terms in polynomial 1 [coefficent][exponent]: ");
            scanf("%d %d",&p1[i].coeff,&p1[i].exp);
        }
    }

    int Sum(struct Poly *p1,struct Poly *p2,struct Poly *p3,int count1,int count2){
        int i=0,j=0,k=0;
        while(i<count1 && j<count2){
            if(p1[i].exp==p2[j].exp){
                p3[k].exp=p1[i].exp;
                p3[k].coeff=p1[i].coeff+p2[j].coeff;
                i++,j++,k++;
            }
            else if(p1[i].exp>p2[j].exp){
                p3[k].exp=p1[i].exp;
                p3[k].coeff=p1[i].coeff;
                i++,k++;
            }
            else{
                p3[k].exp=p2[j].exp;
                p3[k].coeff=p2[j].coeff;
                j++,k++;
            }
        }
        while(i<count1){
            p3[k].exp=p1[i].exp;
            p3[k].coeff=p1[i].coeff;
            i++,k++;
        }
        while(j<count2){
            p3[k].exp=p2[j].exp;
            p3[k].coeff=p2[j].coeff;
            j++,k++;
        }
        return k;
    }

    void display(struct Poly *p1,int count){
        for(int i=0;i<count;i++){
            printf("%dx^%d",p1[i].coeff,p1[i].exp);
            if(i<count-1)
                printf(" + ");
        }
    }
    int main(){
        int count1,count2,count3;
        printf("Enter number of terms in polynomial 1 : ");
        scanf("%d",&count1);
        struct Poly p1[count1];
        Init(count1,p1);
        printf("Enter number of terms in polynomial 2 : ");
        scanf("%d",&count2);
        struct Poly p2[count2];
        Init(count2,p2);
        struct Poly p3[count1+count2];
        count3=Sum(p1,p2,p3,count1,count2);
        display(p3,count3);
        return 0;
    }