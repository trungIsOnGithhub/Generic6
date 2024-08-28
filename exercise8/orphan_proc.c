#include<stdio.h>
#include<stdlib.h>

int main() {
    printf("Started process of PID %d and PPID %d...\n",getpid(),getppid());

    int pid = fork();

    if(pid == 0) {
        printf("I am child, my pid: %d, my parent pid: %d\n",getpid(),getppid());

        sleep(10);

        printf("Now my pid is %d, my parent pid: %d\n",getpid(),getppid());

        exit(0);
    }
    else {
        printf("I am parent, my pid is %d\n",getpid());
    }

    printf("Terminating process of PID %d and PPID %d...\n",getpid());
}