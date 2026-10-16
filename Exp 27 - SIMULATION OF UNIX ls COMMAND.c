#include <stdio.h>
#include <string.h>

int main()
{
    char fn[100], pat[100], temp[200];
    FILE *fp;

    printf("Enter file name: ");
    scanf("%s", fn);

    printf("Enter the pattern: ");
    scanf("%s", pat);

    fp = fopen(fn, "r");

    if (fp == NULL)
    {
        printf("Error: Cannot open file %s\n", fn);
        return 1;
    }

    printf("\nMatching files:\n");

    while (fgets(temp, sizeof(temp), fp) != NULL)
    {
        temp[strcspn(temp, "\n")] = '\0';

        if (strstr(temp, pat) != NULL)
        {
            printf("%s\n", temp);
        }
    }

    fclose(fp);

    return 0;
}
