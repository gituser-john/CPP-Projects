#include<stdio.h>

int prime(int n){
    if(n==0){
        return 1;
    }
    else if(n==1){
        return 0;
    }
    else{
        for(int i=2;i<=n/2;i++){
            if(n%i==0){
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    int n=17;
    if(prime(n)){
        printf("Its a not prime number");
    }
    else{
        printf("its prime");
    }
    return 0;
}