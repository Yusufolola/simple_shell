#include "shell.h"

/**
 * _realloc - Reassign a memory block using malloc and free function
 * @addr: A pointer to the memory re-assigned previously
 * @pre_size: The size in bytes of the allocated space for addr
 * @cur_size: The size for the new memory block.
 *
 * Return: if cur_size == pre_size - addr
 * If cur_size == 0 and addr is not NULL - NULL.
 * Otherwise - a pointer to the reallocated memory block.
 */

void *_realloc(void *addr, unsigned int pre_size, unsigned int cur_size)
{
	void *new;
	char *addr_copy, *bulk;
	unsigned int i;

	if (cur_size == pre_size)
		return (addr);
	if (addr == NULL)
	{
		new = malloc(cur_size);
		if (new == NULL)
			return (NULL);
		return (new);
	}

	if (cur_size == 0 && addr != NULL)
	{
		free(addr);
		return (NULL);
	}

	addr_copy = addr;
	new = malloc(sizeof(*addr_copy) * cur_size);
	if (new == NULL)
	{
		free(addr);
		return (NULL);
	}

	bulk = new;

	for (i = 0; i < pre_size && i < cur_size; i++)
		bulk[i] = *addr_copy++;
	free(addr);
	return (new);
}


/**
 * assign_lineaddr - Reallocates the lineptr variable for _getline.
 * @lineaddr : A buffer to keep an input string
 * @size: The size of lineaddr.
 * @buf: The string to assign to lineaddr.
 * @b: The size of buf.
 */

void assign_lineaddr(char **lineaddr, size_t *size, char *buf, size_t b)
{
	if (*lineaddr == NULL)
	{
		if (b > 120)
			*size = b;
		else
			*size = 120;
		*lineaddr = buf;
	}
	else if (*size < b) 
	{
		if (b > 120)
		*size = b;
		else
			*size = 120;
		*lineaddr = buf;
	}
	else
	{
		_strcpy(*lineaddr, buf);
		free(buf);
	}
}

/**
 * _getline - Reads input from a stream.
 * @lineaddr: A bufer to store the string entry
 * @size: The size of lineaddr in the prototype.
 * @src: The stream to read from.
 *
 * Return: The number of bytes read.
 */
ssize_t _getline(char **lineaddr, size_t *size, FILE *src)
{
	static ssize_t in;
	ssize_t get;
	char a = 'x', *buf;
	int r;

	if (in == 0)
		fflush(src);
	else
		return (-1);
	in = 0;

	buf = malloc(sizeof(char) * 120);
	if (!buf)
		return (-1);
	while (a != '\n')
	{
		r = read(STDIN_FILENO, &a, 1);
		if (r == -1 || (r == 0 && in == 0))
		{
			free(buf);
			return (-1);
		}
		if (r == 0 && in != 0)
		{
			in++;
			break;
		}

		if (in >= 120)
			buf = _realloc(buf, in, in + 1);
		buf[in] = a;
		in++;
	}
	buf[in] = '\0';
	assign_lineaddr(lineaddr, size, buf, in);

	get = in;
	if (r != 0)
		in = 0;
	return (get);
}
