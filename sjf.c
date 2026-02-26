#include <stdio.h>

int main()
{
    int n, i, j;
    printf("Enter number of processes:");
    scanf("%d",&n);

    int p[n],bt[n],wt[n],tat[n];
	for(i=0;i<n;i++)
	{
        p[i]=i+1;
        printf("Enter Burst Time for Process P%d:",p[i]);
        scanf("%d",&bt[i]);
    }


    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++) {
            if(bt[i]>bt[j])
			{
                // Swap burst time
                int temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;

                // Swap process id
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }


    wt[0]=0;
    for(i=1;i<n;i++)
	{
        wt[i]=wt[i-1]+bt[i-1];
    }


    for(i=0;i<n;i++)
	{
        tat[i]=wt[i]+bt[i];
    }


    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i=0;i<n;i++)
	{
        printf("P%d\t%d\t\t%d\t\t%d\n",p[i],bt[i],wt[i],tat[i]);
    }


    float total_wt =0,total_tat=0;
    for(i=0;i<n;i++)
	{
        total_wt+=wt[i];
        total_tat+=tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}
