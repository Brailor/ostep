#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int rc = fork();
    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        // child process
        close(STDOUT_FILENO);
        open("./p4.output", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);

        char *childargs[3] = {strdup("./count.sh"),
                              strdup("p4.c"),
                              NULL};
        execvp(childargs[0], childargs);
    }
    else
    {
        // parent
        wait(NULL);
    }
    return 0;
}