#include "get_next_line.h"

char *ft_strdup(char *src)
{
    char *dest;
    int i = 0;

    while (src[i])
        i++;
    dest = (char *)malloc((i + 1) * sizeof(char));
    if (!dest)
        return (NULL);
    i = 0;
    while(src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE];
    static int i_read;
    static int pos;
    char line[80000];
    int i = 0;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    while(1)
    {
        if(pos >= i_read)
        {
            i_read = read(fd, buffer, BUFFER_SIZE);
            if (i_read <= 0)
                break;
            pos = 0;
        }
        line[i++] = buffer[pos++];
        if (buffer[pos] == '\n')
            break;
    }
    line[i] = '\0';
    if (i == 0)
        return (NULL);
    return (ft_strdup(line));
}
