#include <stdio.h>

#define MAX_BLOCKS 5

void firstFit(int blockSizes[], int m, int processSizes[], int n) {
    int allocation[MAX_BLOCKS];

 
    for (int i = 0; i < MAX_BLOCKS; i++) {
        allocation[i] = -1;
    }

  
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (blockSizes[j] >= processSizes[i]) {
          
                allocation[i] = j;
                blockSizes[j] -= processSizes[i];
                break;
            }
        }
    }

  
    printf("Process No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSizes[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i] + 1);
        } else {
            printf("Not Allocated\n");
        }
    }
}

int main() {
   
    int blockSizes[] = {100, 500, 200, 300, 600};
    int processSizes[] = {212, 417, 112, 426};

    int m = sizeof(blockSizes) / sizeof(blockSizes[0]);
    int n = sizeof(processSizes) / sizeof(processSizes[0]);


    firstFit(blockSizes, m, processSizes, n);

    return 0;
}