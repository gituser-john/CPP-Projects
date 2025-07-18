#include <stdio.h>
#define MAX_FRAMES 10
#define MAX_PAGES 100
void printFrame(int frame[],int frames)
{
printf("Frame: ");
        for (int j = 0; j < frames; ++j) 
        {
            if (frame[j] != -1)
            {
                printf("%d ", frame[j]);
            }
            else
            {
                printf("- ");
            }
        }
        printf("\n");
}
int findLFU(int time[], int freq[], int n) 
{
    int i, min = freq[0], pos = 0;
    for (i = 1; i < n; ++i)
    {
    if((freq[i]==min && time[i]<time[pos])||freq[i]<min)
    {
    min=freq[i];
    pos=i;
    }
    }
    return pos;
}
void lfuPageReplacement(int pages[], int n, int frames) 
{
    int frame[MAX_FRAMES], time[MAX_FRAMES], freq[MAX_FRAMES], counter = 0;
    int i, j, pos, pageFaults = 0, flag1, flag2;    
    for (i = 0; i < frames; ++i) 
    {
        frame[i] = -1;
    }   
    for (i = 0; i < n; ++i) 
    {
        flag1 = flag2 = 0;        
        for (j = 0; j < frames; ++j) 
        {
            if (frame[j] == pages[i]) 
            {
                counter++;
                freq[j] += 1;
                flag1 = flag2 = 1;
                break;
            }
        }        
        if (!flag1) 
        {
            for (j = 0; j < frames; ++j) 
            {
                if (frame[j] == -1) 
                {
                    counter++;
                    pageFaults++;
                    frame[j] = pages[i];
                    time[j] = counter;
                    freq[j] = 1;
                    flag2 = 1;
                    break;
                }
            }
        }        
        if (!flag2) 
        {
            pos = findLFU(time, freq, frames);
            counter++;
            pageFaults++;
            frame[pos] = pages[i];
            time[pos] = counter;
            freq[pos] = 1;
        }       
        if(!flag1)
        {
printFrame(frame,frames);
}
else
{
printf("Page hit\n");
}
    }    
    printf("Total Page Faults: %d\n", pageFaults);
}
int main() 
{
    int pages[MAX_PAGES], n, frames;    
    printf("Enter number of pages: ");
    scanf("%d", &n);    
    printf("Enter reference string: ");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &pages[i]);
    }    
    printf("Enter number of frames: ");
    scanf("%d", &frames);    
    lfuPageReplacement(pages, n, frames);    
    return 0;
}

IPC

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#define ARRAY_SIZE 100
#define SHM_SIZE (ARRAY_SIZE * sizeof(int))
int main() 
{
    int shmid;
    key_t key;
    int *array_ptr;
    pid_t child_pid;
    key = ftok(".", 'x');
    if (key == -1) 
    {
        perror("ftok");
        exit(1);
    }
    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) 
    {
        perror("shmget");
        exit(1);
    }
    child_pid = fork();
    if (child_pid == -1) 
    {
        perror("fork");
        exit(1);
    } 
    else if (child_pid == 0) 
    {
        array_ptr = (int *)shmat(shmid, NULL, 0);
        if (array_ptr == (int *)-1) 
        {
            perror("shmat");
            exit(1);
        }
        int sum = 0;
        for (int i = 0; i < ARRAY_SIZE; i++) 
        {
            sum += array_ptr[i];
        }
        printf("Child process (Reader) Calculated sum : %d\n", sum);
        if (shmdt(array_ptr) == -1) 
        {
            perror("shmdt");
            exit(1);
        }
        exit(0);
    } 
    else 
    {
        array_ptr = (int *)shmat(shmid, NULL, 0);
        if (array_ptr == (int *)-1) 
        {
            perror("shmat");
            exit(1);
        }
        for (int i = 0; i < ARRAY_SIZE; i++) 
        {
            array_ptr[i] = i + 1;
        }
        printf("Parent process (Writer) Array written succsessfully\n");
        if (shmdt(array_ptr) == -1) 
        {
            perror("shmdt");
            exit(1);
        }
        wait(NULL);
    }
    if (shmctl(shmid, IPC_RMID, NULL) == -1) 
    {
        perror("shmctl");
        exit(1);
    }
    return 0;
}