#include <stdio.h>

int main()
{
    char fileName[] = "example.txt";

    FILE *file = fopen(fileName, "w");

    if (file == NULL)
    {
        printf("Error creating file.\n");
        return 1;
    }

    fprintf(file, "This is an example file content.");

    printf("File created successfully: %s\n", fileName);

    fclose(file);

    return 0;
}
