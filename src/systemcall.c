#include <stdio.h>
#include <stdlib.h>
#include<errno.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

void call_exit();
void call_fork();

void call_exit() {
	printf("Calling exit function \n");
	//system call exit
	exit(1);
}

void call_fork()
{
	pid_t pid;
	int rv;

	switch(pid = fork()) {
	case -1:
		perror("fork");
		exit(1);
	case 0:
		printf(" Child\n");
		printf("PID %d \n",getpid());
		printf("Parent PID %d \n",getppid());
		scanf("Waits for input %d",&rv);
		exit(rv);
	default:
		printf("Parent \n");
		printf("PID %d \n",getpid());
		printf("Chid Pid %d\n", pid);
		wait(&rv);
		printf("Parent exits status %d\n",WEXITSTATUS(rv));
	}
}

int main()
{
	int a;
	printf("Type 1 to exit the program \nType 2 see fork example\n");
	scanf("%d",&a);
	switch(a) {
		case 1:
			call_exit();
			break;
		case 2:
			printf("CAlling fork \n");
			call_fork();
			break;
		default:
			scanf("%d",&a);
			printf("Does not exit \n");
			break;
	}
}
