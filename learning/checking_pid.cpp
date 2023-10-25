#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int id = fork();
    id = fork();
    for (int i = 0; i < 100; i++)
    {
        printf("Hello world from id: %d\n", id);
    }
    return 0;
}