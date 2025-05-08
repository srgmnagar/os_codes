#include <stdio.h>

int main() {
    int n, at[20], bt[20], remaining[20], ct[20], tat[20], wt[20];
    int complete = 0, t = 0, minm = 9999, shortest = -1, finish_time;
    int check = 0, i;
    float total_wt = 0, total_tat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter arrival time of P%d: ", i+1);
        scanf("%d", &at[i]);
        printf("Enter burst time of P%d: ", i+1);
        scanf("%d", &bt[i]);
        remaining[i] = bt[i];
    }

    printf("\nGantt Chart:\n");

    while (complete != n) {
        minm = 9999;
        shortest = -1;

        for (i = 0; i < n; i++) {
            if (at[i] <= t && remaining[i] > 0 && remaining[i] < minm) {
                minm = remaining[i];
                shortest = i;
                check = 1;
            }
        }

        if (check == 0) {
            printf("| idle ");
            t++;
            continue;
        }

        // Display running process
        printf("| P%d ", shortest + 1);

        remaining[shortest]--;
        t++;

        if (remaining[shortest] == 0) {
            complete++;
            finish_time = t;
            ct[shortest] = finish_time;
            tat[shortest] = ct[shortest] - at[shortest];
            wt[shortest] = tat[shortest] - bt[shortest];

            total_wt += wt[shortest];
            total_tat += tat[shortest];
        }
        check = 0;
    }

    printf("|\n0");

    int time = 0;
    while (time < t) {
        printf("    %d", ++time);
    }

    printf("\n\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f", total_tat/n);
    printf("\nAverage Waiting Time    = %.2f\n", total_wt/n);
    
    return 0;
}
