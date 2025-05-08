#include <stdio.h>

int main() {
    int pid[10], at[10], bt[10], ct[10], tat[10], wt[10], n, i;
    int completed[10] = {0}, remaining[10];
    int current_time = 0, completed_count = 0;
    int gnatt_index[40] = {-1};
    int gnatt_time[40] = {0};
    int gantt_index = 0;
    int time_quantum;
    float total_wt = 0, tot_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter time quantum: ");
    scanf("%d", &time_quantum);

    for (i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter arrival time of P%d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter burst time of P%d: ", i + 1);
        scanf("%d", &bt[i]);
        remaining[i] = bt[i];
    }

    while (completed_count < n) {
        int executed = 0;
        for (i = 0; i < n; i++) {
            if (remaining[i] > 0 && at[i] <= current_time) {
                executed = 1;
                if (remaining[i] > time_quantum) {
                    current_time += time_quantum;
                    remaining[i] -= time_quantum;
                } else {
                    current_time += remaining[i];
                    remaining[i] = 0;
                    completed_count++;
                    ct[i] = current_time;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];
                    total_wt += wt[i];
                    tot_tat += tat[i];
                }
                gnatt_index[gantt_index] = i;
                gnatt_time[gantt_index] = current_time;
                gantt_index++;
            }
        }

        // If no process was ready, insert idle
        if (!executed) {
            gnatt_index[gantt_index] = -1;
            current_time++;
            gnatt_time[gantt_index] = current_time;
            gantt_index++;
        }
    }

    // Print Gantt Chart
    printf("\nGantt Chart:\n|");
    for (i = 0; i < gantt_index; i++) {
        if (gnatt_index[i] == -1)
            printf(" idle \t|");
        else
            printf(" P%d \t|", gnatt_index[i] + 1);
    }
    printf("\n0");
    for (i = 0; i < gantt_index; i++) {
        printf("\t%d", gnatt_time[i]);
    }

    printf("\n\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f", tot_tat / n);
    printf("\nAverage Waiting Time    = %.2f\n", total_wt / n);

    return 0;
}
