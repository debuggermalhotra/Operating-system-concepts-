#include<stdio.h>

int main(void) {
    int i, q, time=0, burst[15], pri[15], no[15], n, temp, j;
    float x=0, y=0, abt, att;
    printf("Please enter the number of processes: ");
    scanf("%d", &n);
    
    printf("Please enter the burst time and priority of each process\n");
    for(i=0; i<n; i++) {
        scanf("%d", &burst[i]);
        scanf("%d", &pri[i]);
            no[i] = i+1;
            x = x + burst[i];
    }
    
    for(i=0; i<n; i++) {
        for(j=i; j<n; j++) {
            if(pri[j] < pri[i]) {
                temp = pri[j];
                pri[j] = pri[i];
                pri[i] = temp;
                
                temp = burst[j];
                burst[j] = burst[i];
                burst[i] = temp;
                
                temp = no[j];
                no[j] = no[i];
                no[i] = temp;
            }
        }
    }

    for(i=0; i<n; i++) {
        printf("Process %d from %d to %d\n", no[i], time, time+burst[i]);
        time = time + burst[i];
    }
   
    return 0;
}