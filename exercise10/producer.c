#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

#define MAXSIZE 10
#define FIFO_NAME "myfifo"

int main() {
	int fifo_id;
	int fd, n;
	char *r;
	int open_mode=O_RDONLY;

	system("clear");

	r=(char *)malloc(sizeof(char)*MAXSIZE);

	if( (fd=open(FIFO_NAME, open_mode)) < 0 ) {
		printf("\nError: Named pipe cannot be opened\n");
		exit(0);
	}

	while(1) {
		n = read(fd, r, MAXSIZE);
		if(n > 0) printf("\nConsumer read: %s", r);
	}
}
