#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

int main(int argc, char *argv[])
{
    int p1[2], p2[2];
    int pid;

    if (pipe(p1) == -1)
    {
        return (0);
    }
    if (pipe(p2) == -1)
    {
        return (1);
    }
    pid = fork();
    if (pid == -1)
    {
        return (2);
    }
    if (pid == 0)
    {
        close(p1[0]);
        close(p2[1]);
        //child process
        int x;
        if (read(p1[0], &x, sizeof(x)) == -1)
        {
            return (3);
        }
        printf("Recieved %d\n", x);
        x *= 4;
        if (write(p1[1], &x, sizeof(x)) == -1)
        {
            return (4);
        }
        printf("Wrote %d\n", x);
        close(p1[1]);
        close(p2[0]);
    }
    else {
        close(p1[1]);
        close(p2[0]);
        //parent process
        srand(time(NULL));
        int y = rand() % 10;
        
        if (write(p1[1], &y, sizeof(y)) == -1)
        {
            return (5);
        }
        printf("Wrote %d\n", y);
        if (read(p1[0], &y, sizeof(y)) == -1)
        {
            return (6);
        }
        printf("Result is %d\n", y);
        close(p1[0]);
        close(p2[1]);
        wait(NULL);

    }
}