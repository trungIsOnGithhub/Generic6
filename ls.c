#include<stdio.h>
#include<dirent.h>

void quit(char*, int);

int main(int argc, char** argv) {
	DIR* dirop;
	struct dirent* dired;
	
	if (argc != 2) {
		printf("Incorrect number of arguments\n");
		return 1;	
	}
	if ((dirop = opendir(argv[1])) == NULL)
		printf("Cannot open directory\n");
	while((dired = readdir(dirop)) != NULL)
		printf("%10d %s\n", dired>d_ino, dired>d_name);
	closedir(dirop);
}
