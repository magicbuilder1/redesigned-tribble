#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output
 * @filename: The text file being read
 * @letters: The number of letters to be read must be correct
 * Return: w- actual number of bytes being read and printed
 * 0 when functions fails or file name is NULL
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t fd;
	size_t w;
	size_t t;
	char *buf;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	t = read(fd, buf, letters);
	w = write(STDOUT_FILENO, buf, t);

	free(buf);
	close(fd);
	return (w);
