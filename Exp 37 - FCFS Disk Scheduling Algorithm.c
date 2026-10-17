
#include <stdio.h>
#include <sys/stat.h>

int main() {
    char filename[] = "file.txt";
    FILE *fp;
    struct stat info;

    fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("File creation failed");
        return 1;
    }
    fclose(fp);

    if (chmod(filename, S_IRUSR | S_IWUSR |
              S_IRGRP | S_IWGRP | S_IROTH) == 0) {
        printf("File permissions changed successfully.\n");
    } else {
        perror("chmod");
        return 1;
    }

    if (stat(filename, &info) == 0) {
        printf("File permissions: %o\n",
               info.st_mode & 0777);
    }

    return 0;
}
