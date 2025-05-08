#include <stdio.h>

int main() {
    int blockSize[10], processSize[10];
    int blockCount, processCount;
    int allocated[10], holeSize[10];

    printf("Enter number of memory blocks: ");
    scanf("%d", &blockCount);

    printf("Enter sizes of memory blocks:\n");
    for (int i = 0; i < blockCount; i++)
        scanf("%d", &blockSize[i]);

    printf("Enter number of processes: ");
    scanf("%d", &processCount);

    printf("Enter sizes of processes:\n");
    for (int i = 0; i < processCount; i++)
        scanf("%d", &processSize[i]);

    // Initialize allocation array
    for (int i = 0; i < processCount; i++)
        allocated[i] = -1;

    // Best Fit Allocation
    for (int i = 0; i < processCount; i++) {
        int bestIdx = -1;
        for (int j = 0; j < blockCount; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx])
                    bestIdx = j;
            }
        }

        if (bestIdx != -1) {
            // Allocate block to process
            allocated[i] = bestIdx;
            holeSize[i] = blockSize[bestIdx] - processSize[i];
            blockSize[bestIdx] -= processSize[i];
        }
    }

    // Output
    printf("\nProcess No.\tProcess Size\tBlock No.\tHole Created\n");
    for (int i = 0; i < processCount; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocated[i] != -1)
            printf("%d\t\t%d\n", allocated[i] + 1, holeSize[i]);
        else
            printf("Not Allocated\t-\n");
    }

    return 0;
}
