#include <stdio.h>

#define MAX 10

void main() {
    int blockSize[MAX], processSize[MAX], allocated[MAX], holeSize[MAX];
    int blockCount, processCount;

    printf("Enter number of memory blocks: ");
    scanf("%d", &blockCount);
    printf("Enter size of each memory block:\n");
    for (int i = 0; i < blockCount; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    printf("\nEnter number of processes: ");
    scanf("%d", &processCount);
    printf("Enter size of each process:\n");
    for (int i = 0; i < processCount; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processSize[i]);
        allocated[i] = -1; // Initialize allocation to -1 (not allocated)
        holeSize[i] = 0;
    }

    // First Fit allocation
    for (int i = 0; i < processCount; i++) {
        for (int j = 0; j < blockCount; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocated[i] = j; // Allocate process to this block
                holeSize[i] = blockSize[j] - processSize[i]; // Calculate hole
                blockSize[j] -= processSize[i]; // Reduce block size
                break; // Move to next process
            }
        }
    }

    // Output allocation result
    printf("\nProcess No.\tProcess Size\tBlock No.\tHole Size\n");
    for (int i = 0; i < processCount; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocated[i] != -1)
            printf("%d\t\t%d\n", allocated[i] + 1, holeSize[i]);
        else
            printf("Not Allocated\t--\n");
    }
}
