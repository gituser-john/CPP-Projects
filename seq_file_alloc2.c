#include <stdio.h>
#include <string.h>

#define MAX_BLOCKS 100
#define MAX_FILES 20

typedef struct {
    char name[20];
    int start;
    int length;
} File;

int memory[MAX_BLOCKS] = {0};
File files[MAX_FILES];
int fileCount = 0;

void allocateFile() {
    char name[20];
    int start, length;

    printf("Enter file name: ");
    scanf("%s", name);
    printf("Enter starting block (0-%d): ", MAX_BLOCKS - 1);
    scanf("%d", &start);
    printf("Enter number of blocks: ");
    scanf("%d", &length);

    if (start < 0 || start + length > MAX_BLOCKS) {
        printf("Error: File exceeds memory limits.\n");
        return;
    }

    for (int i = start; i < start + length; i++) {
        if (memory[i] == 1) {
            printf("Error: Block %d is already allocated.\n", i);
            return;
        }
    }

    for (int i = start; i < start + length; i++) {
        memory[i] = 1;
    }

    strcpy(files[fileCount].name, name);
    files[fileCount].start = start;
    files[fileCount].length = length;
    fileCount++;

    printf("File allocated successfully.\n");
}

void displayFiles() {
    if (fileCount == 0) {
        printf("No files allocated yet.\n");
        return;
    }

    printf("\n%-15s%-15s%-15s%-20s\n", "File Name", "Start Block", "Length", "Blocks Allocated");
    for (int i = 0; i < fileCount; i++) {
        printf("%-15s%-15d%-15d", files[i].name, files[i].start, files[i].length);
        for (int j = 0; j < files[i].length; j++) {
            printf("%d ", files[i].start + j);
        }
        printf("\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nSequential File Allocation Menu:\n");
        printf("1. Allocate File\n");
        printf("2. Display File Table\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: allocateFile(); break;
            case 2: displayFiles(); break;
            case 3: return 0;
            default: printf("Invalid choice.\n");
        }
    }

    return 0;
}
