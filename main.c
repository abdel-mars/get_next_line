#include "get_next_line.h"

int main() 
{
    int fd = open("fd.txt", O_RDWR | O_CREAT, 777);

//    get_next_line(fd);
//    get_next_line(fd);
   printf("%s", get_next_line(fd));

}
