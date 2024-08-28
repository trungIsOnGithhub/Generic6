#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
// To see zombie process, run command: ps -el | grep [executable_file_name] and looking for Z character in the second column of text output
int main() {
	int pid = fork();
	if (pid == 0) {
		printf("I am child process my pid is: %d - my parent pid is: %d\n", getpid(), getppid());
		exit(0);
	}
	else {
		printf("I am parent process my pid is: %d\n", getpid());
		sleep(100);
		exit(0);
	}
	return 0;
}
