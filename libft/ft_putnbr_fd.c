#include <unistd.h>
#include "ft_itoa.c"

void ft_putnbr_fd(int n, int fd)
{
    write(fd, ft_itoa(n), intasstrlen(n) * sizeof(char));
}
