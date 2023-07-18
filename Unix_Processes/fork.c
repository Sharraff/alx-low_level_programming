#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int id = fork();
    printf("hello world from id: %d\n", id);
    if (id == 0)
    {
        printf("Hello from child process\n");
    }
    else {
        printf("Hello from the maain process\n");
    }
    return (0);
}