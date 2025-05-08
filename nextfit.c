#include <stdio.h>

#define MAX 10

int main() {
    int blockSize[MAX], processSize[MAX], allocated[MAX], holeSize[MAX];
    int blockCount, processCount, lastIndex = 0;

    // Input memory blocks
    printf("Enter number of memory blocks: ");
    scanf("%d", &blockCount);
    printf("Enter size of each memory block:\n");
    for (int i = 0; i < blockCount; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    // Input processes
    printf("\nEnter number of processes: ");
    scanf("%d", &processCount);
    printf("Enter size of each process:\n");
    for (int i = 0; i < processCount; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processSize[i]);
        allocated[i] = -1; // Not allocated initially
        holeSize[i] = 0;
    }

    // Next Fit Allocation
    for (int i = 0; i < processCount; i++) {
        int count = 0, found = 0;

        while (count < blockCount) {
            if (blockSize[lastIndex] >= processSize[i]) {
                // Allocate process
                allocated[i] = lastIndex;
                holeSize[i] = blockSize[lastIndex] - processSize[i];
                blockSize[lastIndex] -= processSize[i];
                found = 1;
                break;
            }

            lastIndex++;
            count++;
        }

        if (found)
            lastIndex++;
    }

    // Output result
    printf("\nProcess No.\tProcess Size\tBlock No.\tHole Size\n");
    for (int i = 0; i < processCount; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocated[i] != -1)
            printf("%d\t\t%d\n", allocated[i] + 1, holeSize[i]);
        else
            printf("Not Allocated\t--\n");
    }

    return 0;
}
