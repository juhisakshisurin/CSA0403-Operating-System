
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, head, disk_size = 200, total = 0;
    int req[100], temp;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request queue: ");
    for (i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (req[j] > req[j + 1]) {
                temp = req[j];
                req[j] = req[j + 1];
                req[j + 1] = temp;
            }
        }
    }

    printf("Head Movement Sequence: %d", head);

    for (i = 0; i < n; i++) {
        if (req[i] >= head) {
            total += abs(head - req[i]);
            head = req[i];
            printf(" -> %d", head);
        }
    }

    total += abs((disk_size - 1) - head);
    head = disk_size - 1;
    printf(" -> %d", head);

    total += disk_size - 1;
    head = 0;
    printf(" -> %d", head);

    for (i = 0; i < n; i++) {
        if (req[i] < (disk_size / 2) && req[i] < 50) {
            total += abs(head - req[i]);
            head = req[i];
            printf(" -> %d", head);
        }
    }

    printf("\nTotal Seek Time: %d", total);
    printf("\nAverage Seek Time: %.2f\n", (float)total / n);

    return 0;
}
