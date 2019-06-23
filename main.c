#include "get_next_line/get_next_line.h"
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int fd;
    char *line;
    int fd2;
    fd2= open(argv[2],O_RDONLY);
    fd = open(argv[1],O_RDONLY);
    get_next_line(fd,&line);
     ft_putendl(line);
    get_next_line(fd2,&line);
     ft_putendl(line);
    get_next_line(fd,&line);
    
    ft_putendl(line);
    free (line);
    
    return(0);
}