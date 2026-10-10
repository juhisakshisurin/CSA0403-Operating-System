#include <stdio.h>
#include <windows.h>
#include <string.h>

int main()
{
    HANDLE hMapFile;
    char *shm_ptr;

    hMapFile = CreateFileMapping(
        INVALID_HANDLE_VALUE,
        NULL,
        PAGE_READWRITE,
        0,
        1024,
        "SharedMemory"
    );

    if (hMapFile == NULL)
    {
        printf("Could not create shared memory.\n");
        return 1;
    }

    shm_ptr = (char *)MapViewOfFile(
        hMapFile,
        FILE_MAP_ALL_ACCESS,
        0,
        0,
        1024
    );

    if (shm_ptr == NULL)
    {
        printf("Could not map shared memory.\n");
        CloseHandle(hMapFile);
        return 1;
    }

    strcpy(shm_ptr, "Hello, shared memory!");

    printf("Data written to shared memory: %s\n", shm_ptr);

    UnmapViewOfFile(shm_ptr);
    CloseHandle(hMapFile);

    return 0;
}
