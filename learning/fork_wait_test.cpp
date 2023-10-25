#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// if the child process executes first, would the wait still be active?

// with no wait, it seems parent keep being executed first, but the parent id that child picks up is no longer the parent pid - it's always 1!

int main(void)
{
    pid_t pid = fork();

    if (pid == 0)
    {
        printf("Child => PPID: %d PID: %d\n", getppid(), getpid());
        exit(EXIT_SUCCESS);
    }
    else if (pid > 0)
    {
        printf("Parent => PID: %d\n", getpid());
    }
    else
    {
        printf("Unable to create child process.\n");
    }

    return EXIT_SUCCESS;
}
