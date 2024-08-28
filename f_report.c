#include<stdio.h>
#include<sys/stat.h>
#include<time.h>

int main(int argc, char** argv) {
	struct stat fstat;
	// first argument will be the executable name
	for (int i=1; i<argc; ++i) {
		printf("%s: ", argv[i]);
		stat(argv[i], &fstat);
		if (S_ISDIR(fstat.st_mode)) {
			printf("is a Directory\n");
		}
		else {
			printf("is a Regular File\n");
		}
		
		printf("--------Properties--------\n");
		printf("Inode Number: %lu\n", fstat.st_ino);
		printf("UID: %o\n", fstat.st_uid);
		printf("GID: %o\n", fstat.st_gid);
		printf("Permission Flag: %o\n", fstat.st_mode%512);
		printf("Bytes Size: %li\n", fstat.st_size);
		printf("Blocks Allocated: %li\n", fstat.st_blocks);
		printf("Last Modification: %s\n", ctime(&fstat.st_atime));
		printf("Last Access: %s\n\n\n", asctime(localtime(&fstat.st_atime)));
	}
	return 0;
}
