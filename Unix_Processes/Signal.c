#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>

int main(int argc, char *argv[])
{
    int pid = fork();
    if (pid == -1)
    {
        return (1);
    }
    
    if (pid == 0)
    {
        while (1)
        {
            /* code */
            printf("some text goes here\n");
            usleep(50000);
        }
        
    } else {
        kill(pid, SIGSTOP);

        int t;
        do {
            printf("Time in seconds for execution: ");
            scanf("%d", &t);

            if (t > 0)
            {
                kill(pid, SIGCONT);
                sleep(t);
                kill(pid, SIGSTOP);
            }

        } while (t > 0);
        
        kill(pid, SIGKILL);
        wait(NULL);
    }
}