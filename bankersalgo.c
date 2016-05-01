#include<stdio.h>

int main(void) {
    int alloc[10][10], maxreq[10][10], need[10][10], avail[10], maxavail[10], i, j, r, p, x, y;
    printf("Please enter the number of resources: ");
    scanf("%d", &r);
    printf("Please enter the number of processes: ");
    scanf("%d", &p);
    
    /* Allocation Table */
    printf("\nPlease enter the allocation table\n");
    for(i=0; i<p; i++) {
        for(j=0; j<r; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }
    
    /* Maximum Available Table */
    printf("\nPlease enter the maximum available table\n");
    for(i=0; i<r; i++) {
        scanf("%d", &maxavail[i]);
    }
    
    /*Available Table */
    printf("\nHere's the available matrix\n");
    for(i=0; i<r; i++) {
        x=0;
        for(j=0; j<p; j++) {
            x = x + alloc[j][i];
        }
        avail[i] = maxavail[i] - x;
        printf("%d\n", avail[i]);
    }
    
    /* Maximum Requirement Table */
    printf("\nPlease enter the maximum requirement table\n");
    for(i=0; i<p; i++) {
        for(j=0; j<r; j++) {
            scanf("%d", &maxreq[i][j]);
        }
    }
    
    /* Need Table*/
    printf("\nHere's the need matrix\n");
    for(i=0; i<p; i++) {
        for(j=0; j<r; j++) {
            need[i][j] = maxreq[i][j] - alloc[i][j];
            printf("%d\t", need[i][j]);
        }
        printf("\n");
    }
    
    /* Safe Sequence */
    printf("\nHere's the safe sequence\n");
    for(y=p; y>0; ) {
        for(i=0; i<p; i++) {
            for(j=0; j<r; j++) {
                if(avail[j]<need[i][j]) {
                    break;
                }
            }
            if(j==r && avail[j-1]>need[i][j-1]) {
                printf("Process %d\n", i+1);
                for(j=0; j<r; j++) {
                    avail[j] = avail[j] + alloc[i][j];
                    need[i][j] = maxavail[j] + 1;
                }
            y--;   
            }
        }
    }
    return 0;
}