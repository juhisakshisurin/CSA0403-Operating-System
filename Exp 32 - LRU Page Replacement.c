
#include <stdio.h>

int main() {
    int pages[20], frames[10], last[10];
    int n, f, i, j, pos, faults = 0, found, time = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++) {
        frames[i] = -1;
        last[i] = 0;
    }

    for (i = 0; i < n; i++) {
        found = 0;
        time++;

        for (j = 0; j < f; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                last[j] = time;
                break;
            }
        }

        if (!found) {
            pos = 0;

            for (j = 0; j < f; j++) {
                if (frames[j] == -1) {
                    pos = j;
                    break;
                }

                if (last[j] < last[pos])
                    pos = j;
            }

            frames[pos] = pages[i];
            last[pos] = time;
            faults++;
        }

        printf("Page %d: ", pages[i]);

        for (j = 0; j < f; j++) {
            if (frames[j] == -1)
                printf("- ");
            else
                printf("%d ", frames[j]);
        }

        if (found)
            printf("Hit");
        else
            printf("Page Fault");

        printf("\n");
    }

    printf("Total Page Faults = %d\n", faults);

    return 0;
}
