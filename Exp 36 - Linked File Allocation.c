
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Block {
    char data[256];
    struct Block *next;
};

int main() {
    struct Block *firstBlock = NULL, *lastBlock = NULL;
    struct Block *newBlock, *temp;
    int blockCount = 0, blockNumber, i;
    char data[256], choice;

    printf("Linked Allocation Simulation\n");

    while (1) {
        printf("\nEnter W to write, R to read, or Q to quit: ");
        scanf(" %c", &choice);

        if (choice == 'Q' || choice == 'q')
            break;

        if (choice == 'W' || choice == 'w') {
            printf("Enter data for the block: ");
            scanf(" %255[^\n]", data);

            newBlock = malloc(sizeof(struct Block));

            if (newBlock == NULL) {
                printf("Memory allocation failed.\n");
                break;
            }

            strcpy(newBlock->data, data);
            newBlock->next = NULL;

            if (firstBlock == NULL)
                firstBlock = newBlock;
            else
                lastBlock->next = newBlock;

            lastBlock = newBlock;
            blockCount++;
            printf("Block %d added.\n", blockCount);
        }
        else if (choice == 'R' || choice == 'r') {
            printf("Enter block number to read (1-%d): ",
                   blockCount);
            scanf("%d", &blockNumber);

            if (blockNumber < 1 || blockNumber > blockCount) {
                printf("Invalid block number.\n");
                continue;
            }

            temp = firstBlock;

            for (i = 1; i < blockNumber; i++)
                temp = temp->next;

            printf("Block %d data: %s\n",
                   blockNumber, temp->data);
        }
    }

    temp = firstBlock;
    while (temp != NULL) {
        struct Block *nextBlock = temp->next;
        free(temp);
        temp = nextBlock;
    }

    return 0;
}
