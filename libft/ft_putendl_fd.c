#include <unistd.h>
#include "ft_strlen.c"

void ft_putendl_fd(char *s, int fd)
{
    write(fd, s, ft_strlen(s) * sizeof(char));
    write(fd, &"\n", sizeof(char));
}
