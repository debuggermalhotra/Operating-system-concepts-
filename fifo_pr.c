#include<stdio.h>

int main(void) {
    int a, x, y, z, i, j, nop, n, pt[20][20], pages[20], k, min;
    printf("Please enter the number of frames: ");
    scanf("%d", &n);
    printf("Please enter the number of pages in the sequence: ");
    scanf("%d", &nop);
    
    printf("Please enter the sequence - \n");
    for(i=0; i<nop; i++) {
        scanf("%d", &pages[i]);
    }
    
    for(i=0; i<20; i++) {
        for(j=0; j<20; j++) {
            pt[i][j] = -1;
        }
    }
    
    k=0;
    for(i=0; i<nop; i++) {
       for(j=0; j<n; j++) {
            if(pt[j][0]==pages[i] || pt[j][0]==-1) {
                break;
            }
        }
        printf("%d", pages[i]);
        if(pt[j][0] == -1 && j<n) {
            pt[j][0] = pages[i];
            pt[j][1] = k;
            k++;
            for(z=0; z<n; z++) {
                printf("\n");
                printf("%d\t%d", pt[z][0], pt[z][1]);
            }
            printf("\n");
        }
        else if(pt[j][0]==pages[i]) {
            for(z=0; z<n; z++) {
                printf("\n");
                printf("%d\t%d", pt[z][0], pt[z][1]);
            }
            printf("\n");
        }
        else if(j==n && pt[j-1][0]!=pages[i]) {
            y = 0;
            min=pt[0][1];
            for(a=1; a<n; a++) {
                if(min>pt[a][1]) {
                    min=pt[a][1];
                    y=a;
                }                
            }
            pt[y][0]=pages[i];
            pt[y][1]=k;
            k++;
            for(z=0; z<n; z++) {
                printf("\n");
                printf("%d\t%d", pt[z][0], pt[z][1]);
            }
            printf("\n");
        }    
        
    }
    
    return 0;
}