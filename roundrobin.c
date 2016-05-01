#include<stdio.h>

int main(void) {
    int i, x=0, q, time, burst[15], n;
    printf("Please enter the time slice: ");
    scanf("%d", &q);
    printf("Please enter the number of processes: ");
    scanf("%d", &n);
    
    printf("Please enter the burst time of each process\n");
    for(i=0; i<n; i++) {
        scanf("%d", &burst[i]);
        x = x + burst[i];
    }
    

    time = 0;
    for( ; time != x; ) {
        for(i=0; i<n; i++) {
            if(burst[i]>=q) {
                printf("Process number %d from %d to %d\n", i+1, time, time+q);
                time = time + q;
                burst[i] = burst[i] - q;
            }
            else if(burst[i]<q && burst[i]>0) {
                printf("Process number %d from %d to %d\n", i+1, time, time+burst[i]);
                time = time + burst[i];
                burst[i] = 0;
            }
        }
    }
    
    
    return 0;
}