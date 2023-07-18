#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    if (mkfifo("myfifo1", 0777) == -1) {
        if (errno != EEXIST) {
            printf("Could not create fifo file\n");
            return (1);
        }
    }

    printf("opening...\n");
    int fd = open("myfifo1", O_WRONLY);
    printf("opened\n");
    int x = 97;
    if (write(fd, &x, sizeof(x)) == -1)
    {
        return (2);
    }
    printf("written");
    close(fd);
    printf("closed");

    return (0);
}