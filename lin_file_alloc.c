#include <stdio.h>
#include <string.h>

#define MAX_BLOCKS 100
#define MAX_FILES 20

// Structure for a memory block
typedef struct Block {
    int id;                 // Block ID
    int used;               // 0 = free, 1 = allocated
    struct Block* next;     // Pointer to next block in file
} Block;

// Structure for a file entry
typedef struct {
    char name[20];
    Block* start;           // Pointer to first block
} File;

Block blocks[MAX_BLOCKS];
File files[MAX_FILES];
int fileCount = 0;

// Initialize all blocks
void initializeBlocks() {
    for (int i = 0; i < MAX_BLOCKS; i++) {
        blocks[i].id = i;
        blocks[i].used = 0;
        blocks[i].next = NULL;
    }
}

// Find a free block index
int findFreeBlock() {
    for (int i = 0; i < MAX_BLOCKS; i++) {
        if (blocks[i].used == 0)
            return i;
    }
    return -1; // No free block
}

// Allocate a new file
void allocateFile() {
    char name[20];
    int n;

    printf("Enter file name: ");
    scanf("%s", name);
    printf("Enter number of blocks needed: ");
    scanf("%d", &n);

    // Count available blocks
    int freeCount = 0;
    for (int i = 0; i < MAX_BLOCKS; i++)
        if (!blocks[i].used)
            freeCount++;

    if (n > freeCount) {
        printf("Not enough free blocks available.\n");
        return;
    }

    // Link blocks together
    Block *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        int idx = findFreeBlock();
        blocks[idx].used = 1;
        blocks[idx].next = NULL;

        if (head == NULL) {
            head = &blocks[idx];
            tail = head;
        } else {
            tail->next = &blocks[idx];
            tail = tail->next;
        }
    }

    // Save file info
    strcpy(files[fileCount].name, name);
    files[fileCount].start = head;
    fileCount++;

    printf("File '%s' allocated successfully.\n", name);
}

// Display all allocated files and their block chains
void displayFiles() {
    if (fileCount == 0) {
        printf("No files allocated yet.\n");
        return;
    }

    printf("\n%-15s%-20s\n", "File Name", "Block Chain");
    for (int i = 0; i < fileCount; i++) {
        printf("%-15s", files[i].name);
        Block* curr = files[i].start;
        while (curr != NULL) {
            printf("%d -> ", curr->id);
            curr = curr->next;
        }
        printf("END\n");
    }
}

// Main menu
int main() {
    int choice;
    initializeBlocks();

    while (1) {
        printf("\nLinked File Allocation Menu:\n");
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
