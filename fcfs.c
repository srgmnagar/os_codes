#include<stdio.h>

void main(){
    int pid[20], at[20], bt[20], wt[20], ct[20],tat[20], avgwt=0, avgtat=0, n, i, temp;
    printf("enter number of Ps: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        pid[i] = i+1;
        printf("enter arrival time of %d: ",pid[i]);
        scanf("%d",&at[i]);
        printf("enter burst time of %d: ",pid[i]);
        scanf("%d",&bt[i]);
    }
    //sorting
    for(i=0;i<n;i++){
        for(int j = 0;j<n-i-1;j++){
            if(at[j+1]<at[j]){
                temp = at[j];
                at[j] = at[j+1];
                at[j+1] = temp;

                temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;

                temp = pid[j];
                pid[j] = pid[j+1];
                pid[j+1] = temp;
            }
        }
    }
    for(i=0;i<n;i++){
        if(i==0){
            ct[i] = at[i] + bt[i];
        }
        else{
            if(at[i]>ct[i-1]){
                ct[i] = at[i] + bt[i];
            }
            else{
                ct[i] = ct[i-1] + bt[i];
            }
        }
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        avgwt += wt[i];
        avgtat += tat[i];
        printf("%d\t|",pid[i]);
    }
    printf("\nPid\tArrival\tBurst\tComplete\tTurn\tWaiting\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("gant chart:\n");
    printf("\n%d\t", (wt[0] - at[0]));
    for (int i = 0; i < n; i++) {
        printf("%d\t", ct[i]);
    }
    printf("\nAverage waiting time: %f", (avgwt / n));
    printf("\nAverage turnaround time: %f", (avgtat / n));
}
