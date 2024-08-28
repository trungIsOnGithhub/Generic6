#include<stdio.h>

void sig_alarm(int sig_no) {
	printf("From sig_alarm function: %d\n", sig_no);
}
int main() {
	if (signal(SIGALRM, sig_alarm) == SIG_ERR)
		printf("Signal Error!");
	alarm(5);
	
	for (int i=0; i<=16; ++i) {
		printf("for loop running i=%d\n", i);
	}
	printf("Main Program Terminated!");
	return 0;
}
