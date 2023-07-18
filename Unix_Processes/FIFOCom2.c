#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>

int main(int argc, char *argv[])
{
    int arr[5];
    int fd = open("sum", O_RDONLY);
    int i;

    if (fd == -1)
    {
        return (-1);
    }
    for (i = 0; i < 5; i++)
    {
        if (read(fd, &arr[i], sizeof(int)) == -1)
        {
            return (2);
        }
        prinf("Recieved %d\n", arr[i]);
    }
    close(fd);

    int sum = 0;
    for (i = 0; i < 5; i++)
    {
        sum += arr[i];
    }
    printf("Result is %d\n", sum);
}