#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>

#define DATA_SIZE = 2000;

void client(int writer_file_des, int reader_file_des) {
    int i,j,n;
    char fname[DATA_SIZE];
    char buff[DATA_SIZE];

    printf("ENTER FILE NAME :");
    scanf("%s",fname);
    printf("CLIENT SENDING REQUEST.....PLEASE WAIT\n");

    sleep(10);
    write(writer_file_des,fname,DATA_SIZE);

    n = read(reader_file_des,buff,DATA_SIZE);
    buff[n] = '\0';

    printf("RESULTS OF CLIENTS ARE......\n");

    write(1,buff,n);
}

void server(int reader_file_des,int writer_file_des) {
    int i,j,n;
    char fname[DATA_SIZE];
    char buff[DATA_SIZE];

    n = read(reader_file_des,fname,DATA_SIZE);
    fname[n]='\0';

    int temp_file_des = open(fname, O_RDONLY);

    sleep(10);

    if(temp_file_des < 0) {
        write(writer_file_des,"can't open",9);
    }
    else {
        n = read(temp_file_des,buff,DATA_SIZE);

        write(writer_file_des,buff,n);
    }
}

int main() {
    int p1[2],p2[2],pid;

    pipe(p1); pipe(p2);

    if(fork() == 0) {
        close(p1[1]); close(p2[0]);

        server(p1[0],p2[1]);
    }
    else {
        close(p1[0]); close(p2[1]);

        client(p1[1], p2[0]);

        wait();
    }

    return 0;
}