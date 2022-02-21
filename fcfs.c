#include<stdio.h>
#include<conio.h>
#define max 30
void main()
{
int i,j;
int n;
int burst_time[max];
int arrival_time[max];
int waiting_time[max];
int completion_time[max];
int process[max];
int turnaround_time[max];
int temp[max];
int t;
float avergage_waiting_time=0;
float avergage_turnaround_time=0;

printf("Enter the number of processes");
scanf("%d",&n);

printf("Enter the process number");
for(i=0;i<n;i++)
    scanf("%d",&process[i]);

printf("Enter the burst time of the process");
for(i=0;i<n;i++)
    scanf("%d",&burst_time[i]);

printf("Enter the arrival time of the process");
for(i=0;i<n;i++)
    scanf("%d",&arrival_time[i]);

    //Applying Bubble Sort Technique to sort according to their burst time
for(i=0;i<n;i++)
{
    for(j=0;j<n-i-1;j++)
    {
        if(arrival_time[j]>arrival_time[j+1])
        {
            t=arrival_time[j];
            arrival_time[j]=arrival_time[j+1];
            arrival_time[j+1]=t;

            t=process[j];
            process[j]=process[j+1];
            process[j+1]=t;

            t=burst_time[j];
            burst_time[j]=burst_time[j+1];
            burst_time[j+1]=t;
        }

    }
}


temp[0]=0;
int time=0;

printf("process\t Burst Time\t Arrival Time\t Completion Time\t Waiting Time\t Turn Around Time\n");
for(i=0;i<n;i++)
{
    waiting_time[i]=0;
    turnaround_time[i]=0;

    completion_time[i]=time+ burst_time[i];
    turnaround_time[i]=completion_time[i]-arrival_time[i];
    waiting_time[i]=turnaround_time[i]- burst_time[i];

    time=time+burst_time[i];

  //  waiting_time[i]=0;
   // turnaround_time[i]=0;
   // temp[i+1]=temp[i]+burst_time[i];
   // waiting_time[i]=temp[i]-arrival_time[i];
   // turnaround_time[i]=waiting_time[i]+burst_time[i];

    avergage_waiting_time=avergage_waiting_time+waiting_time[i];
    avergage_turnaround_time=avergage_turnaround_time+turnaround_time[i];

    printf("%d\t%d\t\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n",process[i],burst_time[i],arrival_time[i],completion_time[i],waiting_time[i],turnaround_time[i]);

}

avergage_waiting_time=avergage_waiting_time/n;
avergage_turnaround_time=avergage_turnaround_time/n;

printf("Average Waiting Time %f\n",avergage_waiting_time);
printf("Average Turnaround Time %f \n",avergage_turnaround_time);

printf("-------Gantt Chart----------\n");
printf("--------------------\n");
for(i=0;i<n;i++)
{
 printf("P%d |",process[i]);
}
printf("\n--------------------\n");
for(i=0;i<n;i++)
{
if(i==0)
{
 printf("0  ");
}
printf("%d  ",completion_time[i]);
}

}
