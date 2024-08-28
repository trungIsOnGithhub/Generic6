#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

#define MAXSIZE 10
#define FIFO_NAME "MY_FIFO"

// Fifo to call a pipe, a way of IPC

// ref https://www.tutorialspoint.com/c_standard_library/c_function_system.htm
// ref https://www.tutorialspoint.com/c_standard_library/c_function_exit.htm

int main() {
	int fifo_id;
	int file_des, n;
	char *r;
	int open_mode = O_RDONLY;

	system("clear");

	r = (char*)malloc(sizeof(char)*MAXSIZE);

	if( (file_des=open(FIFO_NAME, open_mode)) < 0 ) {
		printf("\nError: Pipe %s cannot be opened\n", FIFO_NAME);
		exit(0);
	}

	while(1) {
		n = read(file_des, r, MAXSIZE);
		if(n > 0) printf("\nConsumer read: %s", r);
	}
}