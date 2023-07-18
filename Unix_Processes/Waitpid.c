#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

/**
 * main -
 * 
*/
int main(int argc, char *argv[])
{
    int pid1 = fork();

    if (pid1 == -1)
    {
        printf("Error creating process");
        return (1);
    }
    if (pid1 == 0)
    {
        sleep(4);
        printf("finished execution (%d)\n", getpid());
        return (0);
    }

    int pid2 = fork();
    if (pid2 == -1)
    {
        printf("Error creating process");
        return (2);
    }
    if (pid2 == 0)
    {
        sleep(2);
        printf("finished execution (%d)\n", getpid());
        return (0);
    }

    int pid1_res = waitpid(pid1, NULL, 0);
    printf("Waited for %d\n", pid1_res);
    int pid2_res = waitpid(pid2, NULL, 0);
    printf("Waited for %d\n", pid2_res);

    return (0);

}