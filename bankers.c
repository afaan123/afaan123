#include<stdio.h>
int max[10][10], allocation[10][10], need[10][10];

int avail[10];

int np,nr;

void readmatrix(int matrix[10][10])
{
int i,j;
for(i=0;i<np;i++)
    for(j=0;j<nr;j++)
        scanf("%d",&matrix[i][j]);

}
void display_matrix(int matrix[10][10])
{
int i,j;
for(i=0;i<np;i++)
{
printf("\n P %d",i);
for(j=0;j<nr;j++)
{
printf(" %d",matrix[i][j]);
}
}
}
void calculate_need()
{
int i,j;
for(i=0;i<np;i++)
    for(j=0;j<np;j++)
    need[i][j]=max[i][j]-allocation[i][j];
}

void banker()
{
int i,j,k=0,flag;
int finish[10],safe_seq[10];

for(i=0;i<np;i++)
{
finish[i]=0; //Declare all processes are incomplete
}

for(i=0;i<np;i++)
    {
    flag=0;
    if(finish[i]==0) //Execute incomplete process
    {
    for(j=0;j<nr;j++) //Check a need of each process
    {
    if(need[i][j]>avail[j])
    {
    flag=1; //Break a loop as need is greater than avail and go to next process
    break;
    }
    }
    if(flag==0)//Need is lesser than avail so complete process
    {
        finish[i]=1;
        safe_seq[k]=i;
        k++;
        //Add allocated resources of finished process in available resources
        for(j=0;j<nr;j++)
            avail[j]+=allocation[i][j];

        //start checking from first process again
        i=-1;
    }
    }
    }

flag=0; //check if all processes are completed
for(i=0;i<np;i++)
{
    if(finish[i]==0)
    {
        printf("\n The system is in deadlock");
        flag=1;
        break;
    }

}
if(flag==0)
{
      printf("\n The system is in safe state! Safe Sequence is ==>");
    for(i=0;i<np;i++)
        printf(" P%d",safe_seq[i]);
}
}

void request() {
    int c, pid, request[10][10], B[10][10], i;
    printf("\n Do you want make an additional request for any of the process ? (1=Yes|0=No)");
    scanf("%d", &c);
    if (c == 1) {
        printf("\n Enter process number : ");
        scanf("%d", &pid);
        printf("\n Enter additional request : \n");
        for (i = 0; i < nr; i++) {
            printf(" Request for resource %d : ", i + 1);
            scanf("%d", &request[0][i]);
        }
        for (i = 0; i < nr; i++) {
            if (request[0][i] > need[pid][i]) {
                printf("\n ******Error encountered******\n");
                exit(0);
            }
        }
        for (i = 0; i < nr; i++) {
            avail[i] -= request[0][i];
            allocation[pid][i] += request[0][i];
            need[pid][i] -= request[0][i];
        }
            //Display entered data
    printf("*****Entered data is*******\n\n ");
    printf("\n Initial Allocation \n");
    display_matrix(allocation);

    printf("\n\n Maximum requirements \n");
    display_matrix(max);

    printf("\nAvailable resources:\n");
    for(int j=0;j<nr;j++)
    {
       printf(" %d ",avail[j]);
    }

    //Calculate and display need
    calculate_need();
    printf("\n\n\n Need is \n");
    display_matrix(need);
        banker();
        getch();
    } else {
        exit(0);
    }
}

int main()
{
    int j;

    //read input

    printf("Enter number of processes");
    scanf("%d",&np);
    printf("Enter number of resources");
    scanf("%d",&nr);

    printf("\n Enter initial allocation matrix");
    readmatrix(allocation);

    printf("\n Enter Max requirement matrix");
    readmatrix(max);

    printf("Enter available resources:");
    for(j=0;j<nr;j++)
    {
        scanf("%d",&avail[j]);
    }

    //Display entered data
    printf("*****Entered data is*******\n\n ");
    printf("\n Initial Allocation \n");
    display_matrix(allocation);

    printf("\n\n Maximum requirements \n");
    display_matrix(max);

    printf("\nAvailable resources:\n");
    for(j=0;j<nr;j++)
    {
       printf("%d",avail[j]);
    }

    //Calculate and display need
    calculate_need();
    printf("\n\n\n Need is \n");
    display_matrix(need);

    //Execute processes using bankers
    banker();
    request();
    printf("\n\n\n\n");








}
