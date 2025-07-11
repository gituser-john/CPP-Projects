#include<stdio.h>

typedef struct {
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
} Process;

void sort_process(Process *p1,Process *p2){
    Process temp;
    if(p1->at > p2->at){
        temp =*p1;
        *p1=*p2;
        *p2=temp;   
    }
}

void disp(Process process[],int size){
    for(int i=0;i<size;i++){
        printf("%d\t%d\t%d\t%d\n",process[i].pid,process[i].at,process[i].bt,process[i].ct);
    }
}

void FCFS(Process process[],int size){
    int cur_time = 0;
    for(int i = 0; i < size - 1; i++) {
        for(int j = i + 1; j < size; j++) {
            sort_process(&process[i], &process[j]);
        }
    }
    for(int i=0;i<size;i++){
        if(process[i].at > cur_time){
            cur_time = process[i].at;
        }
        process[i].ct = cur_time + process[i].bt;
        cur_time = process[i].ct;
    }

    disp(process,size);

}

int main(){
    Process process[] = {
        {1,0,1,0,0,0},
        {2,2,2,0,0,0},
        {3,1,3,0,0,0}
    };
    int size = sizeof(process)/sizeof(process[0]);
    FCFS(process,size);
}