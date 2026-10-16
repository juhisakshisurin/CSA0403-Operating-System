
#include <stdio.h>
#include <stdlib.h>

struct Record {
    int recordNumber;
    char data[256];
};

int main() {
    FILE *file;
    struct Record record;
    int recordNumber;

    file = fopen("sequential_file.dat", "wb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("Enter records (0 to stop):\n");

    while (1) {
        printf("Record Number: ");
        scanf("%d", &record.recordNumber);

        if (record.recordNumber == 0)
            break;

        printf("Data: ");
        scanf(" %255[^\n]", record.data);

        fwrite(&record, sizeof(record), 1, file);
    }

    fclose(file);

    file = fopen("sequential_file.dat", "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("Enter record number to read (0 to exit): ");

    while (scanf("%d", &recordNumber) == 1 &&
           recordNumber != 0) {
        rewind(file);

        while (fread(&record, sizeof(record), 1, file) == 1) {
            printf("Record Number: %d\n", record.recordNumber);
            printf("Data: %s\n", record.data);

            if (record.recordNumber == recordNumber)
                break;
        }

        printf("Enter record number to read (0 to exit): ");
    }

    fclose(file);
    return 0;
}
