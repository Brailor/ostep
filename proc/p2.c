#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "../intro/common.h"

volatile int counter = 0;

int main(int argc, char *argv[])
{
    int parent_pid = (int)getpid();
    printf("hello world, (pid: %d)\n", parent_pid);

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
        // simulating some expensive work that takes 5 seconds
        Spin(5);
        // this won't change the parent process's counter variable
        counter = 15;
        printf("did the work!\n");
    }
    else
    {
        // parent process, it will wait for the child to finish
        // 5 seconds in this case
        int rc_wait = wait(NULL);
        printf("hello, I am parent of %d (rc_wait: %d) (pid: %d)\n", rc, rc_wait, parent_pid);
        printf("count is: %d\n", counter);
    }
}