#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int x = 0;

void handle_sigusr1(int sig)
{
    if (x == 0)
    {
        printf("Remember that multiplication is repetitive addition!\n");
    }
}

int main(int argc, char *argv[])
{
    int pid = fork();
    if (pid == -1)
    {
        return (1);
    }
    if (pid == 0)
    {
        //child process
        sleep(5);
        kill(getppid(), SIGUSR1);
    } else {
        struct sigaction sa = { 0 };
        sa.sa_flags = SA_RESTART;
        sa.sa_handler = &handle_sigusr1;
        sigaction(SIGUSR1, &sa, NULL);
        //parent process
        int x;
        printf("What is the result of 3 * 5: ");
        scanf("%d", &x);
        if (x == 5) {
            printf("Right!");
        } else {
            printf("Wrong!");
        }
        wait(NULL);
    }
}