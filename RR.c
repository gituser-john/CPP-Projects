#include<stdio.h>

typedef struct{
    int process_id;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int remaining_burst_time;
    int executed;
} Process;

#define MAX 50
 

int queue_array[MAX];
int rear = - 1;
int front = - 1;

void insert(int add_item)
{
    if (rear == MAX - 1)
    printf("Queue Overflow \n");
    else
    {
        if (front == - 1)
        /*If queue is initially empty */
        front = 0;
        rear = rear + 1;
        queue_array[rear] = add_item;
    }
} /* End of insert() */
 
int delete()
{
    int temp;
    if (front == - 1 || front > rear)
    {
        printf("Queue Underflow \n");
        return -1;
    }
    else
    {
        temp = queue_array[front];
        front = front + 1;

    }
    return temp;
} /* End of delete() */
 


int find_the_shortest_remaining_time(Process process[],int size,int current_time){
    int minIndex = -1;
    int minRemainingTime = 9999;
    for (int i = 0; i < size; i++){
        if(!process[i].executed && process[i].arrival_time<= current_time && process[i].remaining_burst_time > 0){
            if(process[i].remaining_burst_time < minRemainingTime){
                minRemainingTime = process[i].remaining_burst_time;
                minIndex = i;
            }
        }
    }
    return minIndex;
}

void find_TAT_and_WT(Process process[],int size){
    for (int i = 0; i < size; i++)
    {
        process[i].turnaround_time = process[i].completion_time - process[i].arrival_time;
        process[i].waiting_time = process[i].turnaround_time - process[i].burst_time;
    }
}

void RR(Process process[], int size){
    int completed = 0, current_time = 0;

    Process temp;
    for (int i = 0; i < size-1; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if(process[i].arrival_time > process[j].arrival_time){
                temp = process[i];
                process[i] = process[j];
                process[j] = temp;
            }
        }
    }
    int bindex = 0;
    while(completed < size){
        int index = find_the_shortest_remaining_time(process,size,current_time);
        if(index == -1){
            current_time++;
            continue;
        }
        insert(index);
        index=delete();
        if (index == -1) continue;
        for(int i=0; i<3; i++){
            process[index].remaining_burst_time--;
            current_time++;
            int bindex = find_the_shortest_remaining_time(process,size,current_time);
            if(bindex != -1){
                insert(bindex);
            }
            if(process[index].remaining_burst_time == 0){
                process[index].completion_time = current_time;
                completed++;
                process[index].executed = 1;
                break;
            }
        }
    }
    find_TAT_and_WT(process,size);

    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    for (int i = 0; i < size; i++)
    {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\n",process[i].process_id,process[i].arrival_time,process[i].burst_time,process[i].completion_time,process[i].turnaround_time,process[i].waiting_time);
    }
}

int main(){
    Process process[] = {
        {1, 0, 8, 0, 0, 0, 8, 0},
        {2 ,5 ,2 ,0 ,0, 0, 2, 0},
        {3 ,1 ,7 ,0 ,0 ,0, 7, 0},
        {4, 6, 3, 0, 0, 0, 3, 0},
        {5, 8, 5, 0, 0, 0, 5, 0}
    };
    int size = sizeof(process)/sizeof(process[0]);
    RR(process,size);
    return 0;
}