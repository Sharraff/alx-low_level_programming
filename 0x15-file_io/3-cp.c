#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>
#include <unistd.h>

void close_file(int fd);
/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 * Return: 0 on success.
 * Description: If the argument count is incorrect - exit code 97.
 *  If file_from does not exist or cannot be read - exit code 98.
 *  If file_to cannot be created or written to - exit code 99.
 *  If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char **argv)
{
	int from;
	int to;
	int wrote;
	int readed;
	char buff[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	from = open(argv[1], O_RDONLY);
	if (from == -1)
	{
		dprintf(STDERR_FILENO, "Error: cant read from file %s\n", argv[1]);
		exit(98);
	}
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (to == -1)
	{
		dprintf(STDERR_FILENO, "Error: cant write to %s\n", argv[2]);
		exit(99);
	}
	while ((readed = read(from, buff, 1024)) > 0)
	{
		wrote = write(to, buff, readed);
		if (wrote == -1)
		{
			dprintf(STDERR_FILENO, "Error: can't write to %s\n", argv[2]);
			exit(99);
		}
	}
	if (readed == -1)
	{
		dprintf(STDERR_FILENO, "Error: can't read from %s\n", argv[1]);
		exit(98);
	}
	close_file(from);
	close_file(to);
	return (0);
}

/**
 *close_file - closes file descriptors
 *@fd: the file describtor to be closed
 *
 */
void close_file(int fd)
{
	int c;

	c = close(fd);

	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: can't close fd %d\n", fd);
		exit(100);
	}
}
