#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int     fd;
    char    *line;

    fd = open("file_descriptor.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Erro ao abrir o arquivo");
        return (1);
    }

	while ((line = get_next_line(fd)) != NULL)
	{
		if (line[0] != '\0') // ignora linha vazia
			printf("Linha: %s", line);
		free(line);
	}

    close(fd);
    return (0);
}

//cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
//./gnl
