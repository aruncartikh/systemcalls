#include <stdio.h>
#include <stdlib.h>
#include<errno.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include "../include/system_hf.h"
void call_exit();
void call_fork();

void call_exit() {
	printf("Calling exit function \n");
	exit(1); //system call exit
}

void call_fork()
{
	pid_t pid;
	int rv;

	// fork creates a child with a different pid
	// return value -1: error 0: child process >0: parent process
	printf("Calling fork - Child process to be born\n");
	switch(pid = fork()) {
	case -1:
		perror("fork");
		exit(1);
	case 0:
		printf("Child Process ");
		printf("PID %d ",getpid());         //get pid
		printf("Parent PID %d \n",getppid()); //get parent pid
		scanf("%d",&rv);
		exit(rv);
	default:
		printf("Parent Process running ");
		printf("PID %d ",getpid());
		printf("Chid Pid %d\n", pid);
		printf("Waiting for the child process to exit\n");
		wait(&rv);
		printf("Parent exits status %d\n",WEXITSTATUS(rv));
	}
}

int main()
{
	int a;
	a = show_menu();
	switch (a) {
		case 1:
			call_exit();
			break;
		case 2:
			call_fork();
			break;
		case 3:
			file_operations();
			break;
		default:
			printf("Wrong data Exiting");
			break;
	}
}
