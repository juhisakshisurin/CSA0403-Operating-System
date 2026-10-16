#include <stdio.h>

#define LINES_PER_PAGE 10

int main()
{
    FILE *file;
    char filename[100];
    char line[1000];
    int lineCount = 0;

    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file) != NULL)
    {
        printf("%s", line);
        lineCount++;

        if (lineCount % LINES_PER_PAGE == 0)
        {
            printf("--More-- (Press Enter to continue...)");
            getchar();
            getchar();
        }
    }

    fclose(file);

    return 0;
}
