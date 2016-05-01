#include<stdio.h>

int main(void) {
    int i, j, n, m, a[20], b[20], temp;
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
    
    for(i=0; i<n; i++) {
        for(j=i+1; j<n; j++) {
            if(a[i] < a[j]) {
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }

    for(i=0, j=0; i<m && j<n; i++) {  
        if(a[j] >= b[i]) {
            printf("%dk for %dk\n", a[j], b[i]);
            j++;
            continue;
        }
         
        else {
            printf("NO SPACE CAN BE ALLOCATED FOR THIS MEMORY SIZE: %d\n", b[i]);
        }
    }
        
    return 0;
}