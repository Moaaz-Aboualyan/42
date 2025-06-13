/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboualy <moaazahmedaboualyan@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 15:17:44 by maboualy          #+#    #+#             */
/*   Updated: 2025/06/13 19:46:49 by maboualy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>     // open
#include <stdio.h>     // printf, perror
#include <stdlib.h>    // exit
#include "get_next_line_bonus.h"

void	test_file(const char *filename)
{
	int		fd;
	char	*line;
	int		i = 0;

	printf("=== Testing file: %s ===\n", filename);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return;
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Line %d: %s", ++i, line);
		free(line);
	}
	close(fd);
	printf("=== End of file: %s ===\n\n", filename);
}

void	test_stdin(void)
{
	char *line;

	printf("=== Testing STDIN (enter lines, press Ctrl+D to stop) ===\n");
	while ((line = get_next_line(0)) != NULL)
	{
		printf("You typed: %s", line);
		free(line);
	}
	printf("=== End of STDIN test ===\n\n");
}

void	test_multiple_fds(const char *file1, const char *file2)
{
	int		fd1 = open(file1, O_RDONLY);
	int		fd2 = open(file2, O_RDONLY);
	char	*line1, *line2;

	if (fd1 < 0 || fd2 < 0)
	{
		perror("Error opening one of the files");
		if (fd1 >= 0) close(fd1);
		if (fd2 >= 0) close(fd2);
		return;
	}

	printf("=== Testing alternating calls on two FDs ===\n");
	while (1)
	{
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
		if (!line1 && !line2)
			break;
		if (line1)
		{
			printf("[File1] %s", line1);
			free(line1);
		}
		if (line2)
		{
			printf("[File2] %s", line2);
			free(line2);
		}
	}
	close(fd1);
	close(fd2);
	printf("=== End of alternating FD test ===\n\n");
}

int	main(void)
{
	test_file("tests/empty.txt");
	test_file("tests/one_line.txt");
	test_file("tests/multiple_lines.txt");
	test_file("tests/no_newline_at_end.txt");
	test_file("tests/long_line.txt");
	test_file("tests/only_new_lines.txt");
	test_stdin(); // optional: comment if not needed
	test_multiple_fds("tests/multiple_lines.txt", "tests/one_line.txt");
	return (0);
}
