#include <stdlib.h>
#include "ft_strlen.c"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    unsigned int i;
    char *new_s;

    new_s = malloc((ft_strlen(s) + 1) * sizeof(char));
    if (!new_s)
        return (0);
    i = 0;
    while (s[i])
    {
        new_s[i] = (*f)(i, s[i]);
        i++;
    }
    new_s[i] = 0;
    return (new_s);
}
