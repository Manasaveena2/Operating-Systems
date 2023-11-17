#include <stdio.h>

#define MAX_FRAMES 3

void lruPageReplacement(int pages[], int n) {
    int frames[MAX_FRAMES];
    int frameCount = 0;

    int pageFaults = 0;

   
    for (int i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int currentPage = pages[i];

       
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
               
                int lruIndex = n + 1;
                for (int j = 0; j < MAX_FRAMES; j++) {
                    int k;
                    for (k = i - 1; k >= 0; k--) {
                        if (frames[j] == pages[k]) {
                            break;
                        }
                    }
                    if (k < lruIndex) {
                        lruIndex = k;
                    }
                }

                
                frames[lruIndex] = currentPage;
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
    
    int pages[] = {1, 3, 0, 3, 5, 6, 3};

    int n = sizeof(pages) / sizeof(pages[0]);

    
    lruPageReplacement(pages, n);

    return 0;
}
