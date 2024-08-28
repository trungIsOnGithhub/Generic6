#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

#define MAXSIZE 10
n=read(file_des, r, MAXSIZE); if(n > 0)

#define FIFO_NAME "MY_FIFO"

// ref https://www.tutorialspoint.com/c_standard_library/c_function_system.htm
// ref https://www.tutorialspoint.com/c_standard_library/c_function_exit.htm
// ref https://daynhauhoc.com/t/ham-fflush-stdin-dung-de-lam-gi/1874/2
// ref https://www.geeksforgeeks.org/input-output-system-calls-c-create-open-close-read-write/

int main() {
	int fifo_id;
	int file_des, n;
	char* w;
	int open_mode = O_WRONLY;
	fifo_id = mkfifo(FIFO_NAME, 0755);

	system("clear");

	if(fifo_id == -1) {
		printf("\nError: Named pipe cannot be Created\n");
		exit(0);
	}

	data = (char *)malloc(sizeof(char)*MAXSIZE);

	if( (file_des = open(FIFO_NAME, open_mode)) < 0 ) {
		printf("\nError: Pipe %s cannot be opened\n", FIFO_NAME);
		exit(0);
	}
	while(1) {
		printf("\nProducer :");
		fflush(stdin);

		read(0, data, MAXSIZE);

		fflush(stdin);
		n = write(file_des, data, MAXSIZE);

		if(n > 0) printf("\nProducer sent: %s", data);
	}
}