#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>


int global;


int main()
{
    pid_t child_pid;
    int status;
    int local = 0;

    child_pid = fork();

    if (child_pid >= 0)
    {
        if (child_pid == 0)
        {
            printf("child process!\n");

            local++;
            global++;

            printf("child PID = %d, parent pid = %d\n", getpid(), getppid());
            printf("\n childs's local = %d, child's global = %d\n", local, global);

            char *cmd[] = {"whoami", (char*)0};
            return execv("/usr/bin", cmd);
        }
        else {
            printf("parent process!\n");
            printf("parent PID = %d, child pid = %d\n", getpid(), child_pid);
            wait(&status);
            printf("Child exit code: %d\n", WEXITSTATUS(status));

            printf("\n parent'z local = %d, parent's global = %d\n", local, global);

            printf("Parent says bye!\n");
            exit(0);
        }
    }
    else {
        perror("fork");
        exit(0);
    }
}