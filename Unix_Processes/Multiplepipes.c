#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>


/**
 * main - this program creates multipe pipe operators with
 *        three process and sends a number from the main process
 *        the children processes with 5 and added consecutively
 *        the result returned to the main process and printed. 
 * 
 * Return: 0 on sucess, any number otherwise.
*/
int main(int argc, char *argv[])
{
    int fd[3][2];
    int i;

    for (i = 0; i < 3; i++)
    {
        if (pipe(fd[i]) < 0)
        {
            return (1);
        }
    }

    int pid1 = fork();
    if (pid1 < 0)
    {
        return (2);
    }

    if (pid1 == 0)
    {
        //child process 1
        close(fd[0][1]);
        close(fd[1][0]);
        close(fd[2][0]);

        int x = 0;

        if (read(fd[0][0], &x, sizeof(int)) < 0)
        {
            return (3);
        }
        x += 5;
        if (write(fd[1][1], &x, sizeof(int)) < 0)
        {
            return (4);
        }
        close(fd[0][0]);
        close(fd[1][1]);
        return (0);
    }
    int pid2 = fork();
    
    if (pid2 < 0)
    {
        return (5);
    }

    if (pid2 == 0)
    {
        //child process 2
        close(fd[0][0]);
        close(fd[0][1]);
        close(fd[1][1]);
        close(fd[2][0]);

        int x = 0;

        if (read(fd[1][0], &x, sizeof(int)) < 0)
        {
            return (6);
        }
        x += 5;
        if (write(fd[2][1], &x, sizeof(int)) < 0)
        {
            return (7);
        }
        close(fd[1][0]);
        close(fd[2][1]);
        return (0);
    }
    //parent process
    close(fd[0][0]);
    close(fd[1][0]);
    close(fd[1][1]);
    close(fd[2][1]);

    int x = 0;

    printf("Input number: ");
    scanf("%d", &x);

    if (write(fd[0][1], &x, sizeof(int)) < 0)
    {
        return (8);
    }
    if (read(fd[2][0], &x, sizeof(int)) < 0)
    {
        return (9);
    }
    printf("Result is %d\n", x);

    close(fd[0][1]);
    close(fd[2][0]);

    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    return (0);
}