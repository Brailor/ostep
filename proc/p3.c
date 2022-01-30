#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int parent_pid = (int)getpid();
    printf("hello world (pid: %d)\n", parent_pid);

    int rc = fork();
    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        // child process
        printf("hello, I am child (pid: %d)\n", (int)getpid());

        char *childargs[3];
        // original example
        // childargs[0] = strdup("wc");
        childargs[0] = strdup("./count.sh");
        childargs[1] = strdup("p3.c");
        childargs[2] = NULL;

        // the file must be in the $PATH if it is not an absolute or relative file!
        int res = execvp(childargs[0], childargs);

        // this wont print out if `execvp` is successful
        printf("res: %d\n", res);
    }
    else
    {
        int rc_wait = wait(NULL);
        printf("hello, I am parent of %d (rc_wait: %d) (pid: %d)\n", rc, rc_wait, parent_pid);
    }

    return 0;
}