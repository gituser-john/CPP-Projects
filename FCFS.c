#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int id;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int ex;
} Process;

void bubble_sort(Process process[], int n){
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (process[j].at > process[j+1].at)
            {
                Process temp = process[j];
                process[j] = process[j+1];
                process[j+1] = temp;
            }
        }
    }
}

void fcfs(Process process[], int n){
    bubble_sort(process,n);

    int time = 0;
    for (int i = 0; i < n; i++)
    {
        if (time < process[i].at)
        {
            time = process[i].at;
        }
        process[i].ct = time + process[i].bt;
        process[i].tat = process[i].ct - process[i].at;
        process[i].wt = process[i].tat - process[i].bt;
        time = process[i].ct;
    }
}

void disp(Process process[], int n){
    float tat=0,wt=0;
    printf("p_id\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n",
        process[i].id,
        process[i].at,
        process[i].bt,
        process[i].ct,
        process[i].tat,
        process[i].wt);
        tat += process[i].tat;
        wt += process[i].wt;
    }
    printf("Avg tat is : %.2f\n",tat/n);
    printf("Avg wt is : %.2f\n",wt/n);
    
}

int main(){
    int n;
    printf("Enter number of processes");
    scanf("%d",&n);

    Process process[n];

    for (int i = 0; i < n; i++)
    {
        process[i].id = i+1;
        printf("Enter at :");
        scanf("%d",&process[i].at);
        printf("Enter bt :");
        scanf("%d",&process[i].bt);
        process[i].ex = 0;
    }

    fcfs(process,n);
    disp(process,n);
    return 0;
}