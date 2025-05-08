#include <stdio.h>

int main() {
    int n, i, j;
    int at[20], bt[20], ct[20], tat[20], wt[20], p[20], completed[20] = {0};
    int current_time = 0, completed_count = 0;
    int min_bt, index;
    float total_tat = 0, total_wt = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("Enter arrival time of P%d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter burst time of P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

   while(completed_count < n) {
        min_bt = 9999;
        index = -1;
        for(i=0;i<n;i++){
            if(bt[i]<min_bt && completed[i]==0 && at[i] <= current_time){
                min_bt=bt[i];
                index=i;
            }
        }
    
        if(index != -1) {
            current_time += bt[index];
            ct[index] = current_time;
            tat[index] = ct[index] - at[index];
            wt[index] = tat[index] - bt[index];

            total_tat += tat[index];
            total_wt += wt[index];

            completed[index] = 1;
            completed_count++;
            printf("P%d\t|", p[index]);
        } else {
            current_time++; 
        }
    
   }
       
   printf("\n0");
   for(i=0; i<n; i++) {
       printf("\t%d", ct[i]);
   }
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f", total_tat / n);
    printf("\nAverage Waiting Time    = %.2f", total_wt / n);

    return 0;
}
