#include <stdio.h>
#include <windows.h>
#include <string.h>

#define PIPE_NAME "\\\\.\\pipe\\OSMessageQueue"

int main(int argc, char *argv[])
{
    HANDLE hPipe;
    HANDLE hProcess;
    STARTUPINFOA si;
    PROCESS_INFORMATION pi;
    char buffer[100];
    char command[300];
    DWORD written, read;

    if (argc > 1 && strcmp(argv[1], "consumer") == 0)
    {
        hPipe = CreateFileA(
            PIPE_NAME,
            GENERIC_READ,
            0,
            NULL,
            OPEN_EXISTING,
            0,
            NULL
        );

        if (hPipe == INVALID_HANDLE_VALUE)
        {
            printf("Consumer: Unable to connect to message queue.\n");
            return 1;
        }

        if (ReadFile(hPipe, buffer, sizeof(buffer) - 1, &read, NULL))
        {
            buffer[read] = '\0';
            printf("Consumer: Data received from message queue: %s\n", buffer);
        }

        CloseHandle(hPipe);
        return 0;
    }

    hPipe = CreateNamedPipeA(
        PIPE_NAME,
        PIPE_ACCESS_OUTBOUND,
        PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,
        1,
        1024,
        1024,
        0,
        NULL
    );

    if (hPipe == INVALID_HANDLE_VALUE)
    {
        printf("Unable to create message queue.\n");
        return 1;
    }

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    sprintf(command, "\"%s\" consumer", argv[0]);

    if (!CreateProcessA(
        NULL,
        command,
        NULL,
        NULL,
        FALSE,
        0,
        NULL,
        NULL,
        &si,
        &pi))
    {
        printf("Unable to create consumer process.\n");
        CloseHandle(hPipe);
        return 1;
    }

    ConnectNamedPipe(hPipe, NULL);

    strcpy(buffer, "Hello, message queue!");

    if (WriteFile(hPipe, buffer, strlen(buffer), &written, NULL))
    {
        printf("Producer: Data sent to message queue: %s\n", buffer);
    }

    WaitForSingleObject(pi.hProcess, INFINITE);

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    CloseHandle(hPipe);

    return 0;
}
