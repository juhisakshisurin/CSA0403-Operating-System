
#include <stdio.h>

struct Block {
    int blockNumber;
    char data[256];
};

int main() {
    FILE *file;
    struct Block block;
    int indexBlock[100];
    int blockNumber, i;

    for (i = 0; i < 100; i++)
        indexBlock[i] = -1;

    file = fopen("indexed_file.dat", "wb");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("Enter blocks (0 to stop):\n");

    while (1) {
        printf("Block Number: ");
        scanf("%d", &block.blockNumber);

        if (block.blockNumber == 0)
            break;

        if (block.blockNumber < 1 || block.blockNumber >= 100 ||
            indexBlock[block.blockNumber] != -1) {
            printf("Invalid or duplicate block number.\n");
            continue;
        }

        printf("Data: ");
        scanf(" %255[^\n]", block.data);

        indexBlock[block.blockNumber] = (int)ftell(file);
        fwrite(&block, sizeof(block), 1, file);
    }

    fclose(file);

    file = fopen("indexed_file.dat", "rb");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (1) {
        printf("Enter block number to read (0 to exit): ");
        scanf("%d", &blockNumber);

        if (blockNumber == 0)
            break;

        if (blockNumber < 1 || blockNumber >= 100 ||
            indexBlock[blockNumber] == -1) {
            printf("Block not found.\n");
            continue;
        }

        fseek(file, indexBlock[blockNumber], SEEK_SET);
        fread(&block, sizeof(block), 1, file);

        printf("Block Number: %d\n", block.blockNumber);
        printf("Data: %s\n", block.data);
    }

    fclose(file);
    return 0;
}
