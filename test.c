# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <strings.h>

int main()
{
    int arr;
    arr = 33;

    int x = 1;
    if((arr >> 0) & x) 
        printf("send 1");
}

