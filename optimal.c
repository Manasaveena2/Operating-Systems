#include <stdio.h>
#include <limits.h>

#define MAX_FRAMES 3

int findOptimalPage(int pages[], int frames[], int start, int end) {
    int index = -1;
    int farthest = start;
    for (int i = 0; i < MAX_FRAMES; i++) {
        int j;
        for (j = start; j < end; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    index = i;
                }
                break;
            }
        }
        if (j == end) {
            return i;
        }
    }
    return (index == -1) ? 0 : index;
}

void optimalPageReplacement(int pages[], int n) {
    int frames[MAX_FRAMES];
    int frameCount = 0;

    int pageFaults = 0;

    
    for (int i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int currentPage = pages[i;

        
        int pageInFrame = 0;
        for (int j = 0; j < frameCount; j++) {
            if (frames[j] == currentPage) {
                pageInFrame = 1;
                break;
            }
        }

        if (!pageInFrame) {
            
            if (frameCount < MAX_FRAMES) {
                
                frames[frameCount++] = currentPage;
            } else {
                
                int index = findOptimalPage(pages, frames, i + 1, n);

                
                frames[index] = currentPage;
            }

           
            pageFaults++;

           
            printf("Page Fault %d: [", pageFaults);
            for (int j = 0; j < frameCount; j++) {
                printf("%d", frames[j]);
                if (j < frameCount - 1) {
                    printf(", ");
                }
            }
            printf("]\n");
        }
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
}

int main() {
    
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};

    int n = sizeof(pages) / sizeof(pages[0]);

    
    optimalPageReplacement(pages, n);

    return 0;
}
