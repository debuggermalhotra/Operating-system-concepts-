#include<stdio.h>

int main(void) {
    int i, j, n, m, a[20], b[20];
    printf("Please enter the number of memory spaces: ");
    scanf("%d", &n);
    printf("Please enter all the available memory spaces - \n");
    for (i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    
    printf("Please enter the number of allocations to be made: ");
    scanf("%d", &m);
    printf("Please enter sizes of all the allocations - \n");
    for (i=0; i<m; i++) {
        scanf("%d", &b[i]);
    }
    
    /* First FIT */
    
    for(i=0; i<m; i++) {
        for(j=0; j<n; j++) {
            if(a[j] >= b[i]) {
                printf("%dk for %dk\n", a[j], b[i]);
                a[j] = -1;
                break;
            }
        }        
        if(j==n && a[j-1]<b[i]) {
            printf("NO SPACE CAN BE ALLOCATED FOR THIS MEMORY SIZE: %d\n", b[i]);
        }
    }
        
    return 0;
}