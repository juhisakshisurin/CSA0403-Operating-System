#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main()
{
    char pattern[100];
    char filename[100];
    char line[MAX_LINE_LENGTH];
    FILE *file;

    printf("Enter the pattern: ");
    scanf("%s", pattern);

    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    printf("\nMatching lines:\n");

    while (fgets(line, sizeof(line), file) != NULL)
    {
        if (strstr(line, pattern) != NULL)
        {
            printf("%s", line);
        }
    }

    fclose(file);

    return 0;
}
