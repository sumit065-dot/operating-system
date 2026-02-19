// write a program in Linux for FCFS//


#include <stdio.h>

int main() {
    int n, i;
    int at[10], bt[10], ct[10], tat[10], wt[10];
    int time = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nEnter Arrival Time of P%d: ", i+1);
        scanf("%d", &at[i]);
        printf("Enter Burst Time of P%d: ", i+1);
        scanf("%d", &bt[i]);
    }

    for(i = 0; i < n; i++) {
        if(time < at[i])
            time = at[i];

        ct[i] = time + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        time = ct[i];
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}
