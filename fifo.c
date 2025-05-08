#include <stdio.h>

int main() {
    int frames, pages, i, j, k, pageFaults = 0;
    int page[100], frame[10], index = 0, found;

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    printf("Enter the page reference string:\n");
    for(i = 0; i < pages; i++) {
        scanf("%d", &page[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    // Initialize frame to -1 (empty)
    for(i = 0; i < frames; i++) {
        frame[i] = -1;
    }

    printf("\nPage\tFrames\t\tPage Fault\n");

    for(i = 0; i < pages; i++) {
        found = 0;

        // Check if page is already in frame
        for(j = 0; j < frames; j++) {
            if(frame[j] == page[i]) {
                found = 1;
                break;
            }
        }

        if(!found) {
            frame[index] = page[i];
            index = (index + 1) % frames; // FIFO
            pageFaults++;
        }

        // Print current state
        printf("%d\t", page[i]);
        for(k = 0; k < frames; k++) {
            if(frame[k] != -1)
                printf("%d ", frame[k]);
            else
                printf("- ");
        }
        printf("\t\t%s\n", found ? "No" : "Yes");
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);
    return 0;
}
