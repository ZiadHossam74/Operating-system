// CPU-Scheduling-Algorithm-In-C
// Shortest Job First(SJF) Scheduling Algorithm(Non Pre-emptive)

#include<stdio.h>
#include<malloc.h>

void main()
{
    int n, i, j, pos, temp, * bt, * wt, * tat, * p, *at, * rd;
    float avgwt = 0, avgtat = 0;
    printf("\n Enter the number of processes : ");
    scanf("%d", &n);

    p = (int*)malloc(n * sizeof(int));
    bt = (int*)malloc(n * sizeof(int));
    wt = (int*)malloc(n * sizeof(int));
    tat = (int*)malloc(n * sizeof(int));
    at = (int*)malloc(n * sizeof(int));
    rd = (int*)malloc(n * sizeof(int));

    printf("\n Enter the Arrival time and the burst time for each process \n");
    for (i = 0; i < n; i++)
    {
        
        printf(" Arrival time for P%d : ", i);
        scanf("%d", &at[i]);
        printf(" Burst time for P%d : ", i);
        scanf("%d", &bt[i]);
        p[i] = i;
    }
    // sort arrival time
    for (i = 0; i < n; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (at[j] < at[pos])
            {
                pos = j;
            }
        }
        // arival time
        temp = at[i];
        at[i] = at[pos];
        at[pos] = temp;
        // burst time
        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;
        // process
        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }

    int time = 0;
    wt[0] = 0;
    tat[0] = bt[0];
    time = bt[0];
    avgwt += wt[0];
    avgtat += tat[0];
    int c = 0;
    int c2 = 1;
    for (; c2 < n; )
    {
       
        for (i = c2; i < n; i++)
        {
            if (at[i] <= time) {
                rd[c] = i;
                c++;
                c2 = i+1;
            }
        }
        
       
        for (i = 0; i < c; i++)
        {
            pos = i;
            for (j = i + 1; j < c; j++)
            {
                if (bt[rd[j]] < bt[rd[pos]])
                {
                    rd[pos] = rd[j];
                }
            }
            temp = rd[i];
            rd[i] = rd[pos];
            rd[pos] = temp;
        }
        // calc wt tat
        for (i = 0 ; i < c; i++)
        {
            wt[rd[i]] = time - at[rd[i]];
            time += bt[rd[i]];
            tat[rd[i]] = wt[rd[i]] + bt[rd[i]];
            avgwt += wt[rd[i]];
            avgtat += tat[rd[i]];
        }
        c = 0;
    }
    avgwt = avgwt / n;
    avgtat = avgtat / n;
    printf("\n Average Waiting Time = %f \n Average Turnaround Time = %f \n", avgwt, avgtat);
    
    printf("\n PROCESS \t Arrival TIME\t BURST TIME \t \n");
    printf("--------------------------------------------------------------\n");
    for(i=0; i<n; i++)
    {
        printf(" P%d \t\t %d \t\t %d \n", p[i], at[i], bt[i]);
    }

}
