#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: name of the file to read
 * @letters: number of letters it should read and print
 *
 * Return: actual number of letters it could read and print,
 * or 0 if it fails
 *
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char *buffer;
	ssize_t r_bytes, w_bytes;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(fd);
		return (0);
	}

	r_bytes = read(fd, buffer, letters);
	if (r_bytes == -1)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	w_bytes = write(STDOUT_FILENO, buffer, r_bytes);
	if (w_bytes == -1 || w_bytes != r_bytes)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	free(buffer);
	close(fd);
	return (w_bytes);
}
