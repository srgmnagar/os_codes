#include <stdio.h>
#include <stdbool.h>

int main() {
    int n, m, i, j, k;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    int alloc[n][m], max[n][m], need[n][m], avail[m];
    bool finish[n];
    int safeSeq[n], index = 0;

    // Input Allocation Matrix
    printf("Enter allocation matrix:\n");
    for(i = 0; i < n; i++) {
        printf("Process %d: ", i);
        for(j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);
    }

    // Input Max Matrix
    printf("Enter max matrix:\n");
    for(i = 0; i < n; i++) {
        printf("Process %d: ", i);
        for(j = 0; j < m; j++)
            scanf("%d", &max[i][j]);
    }

    // Input Available Resources
    printf("Enter available resources: ");
    for(i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    // Calculate Need Matrix = Max - Allocation
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Initialize finish flags
    for(i = 0; i < n; i++)
        finish[i] = false;

    // Banker's Algorithm
    for(k = 0; k < n; k++) {
        for(i = 0; i < n; i++) {
            if(!finish[i]) {
                bool canProceed = true;
                for(j = 0; j < m; j++) {
                    if(need[i][j] > avail[j]) {
                        canProceed = false;
                        break;
                    }
                }
                if(canProceed) {
                    for(j = 0; j < m; j++)
                        avail[j] += alloc[i][j];

                    safeSeq[index++] = i;
                    finish[i] = true;
                }
            }
        }
    }

    // Check if all processes are finished
    bool isSafe = true;
    for(i = 0; i < n; i++) {
        if(!finish[i]) {
            isSafe = false;
            break;
        }
    }

    if(isSafe) {
        printf("\nSystem is in a SAFE state.\nSafe sequence: ");
        for(i = 0; i < n; i++)
            printf("P%d ", safeSeq[i]);
        printf("\n");
    } else {
        printf("\nSystem is NOT in a safe state.\n");
    }

    return 0;
}
