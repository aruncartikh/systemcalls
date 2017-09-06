#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>

void file_operations() {
	int fd1,fd2;
	char *c;
	int length,l;

	c = (char *)malloc(100 * sizeof(char));

	printf("File open \n");
	if ((fd1 = open("/home/arun/C/syscalls/systemcalls/README.md", O_RDWR | O_CREAT | O_APPEND, 0644)) < 0) {
		perror("READ ME");
		free(c);
		return;
	}

	printf("File read \n");
	length = read(fd1,c,100);
	printf("Called the read() %d\n",length);
	c[length] ='\0';
	printf("Data in the file is %s",c);

	printf("File lseek \n");
	l = lseek(fd1, 0, SEEK_CUR);
	printf("Current lseek %d \n",l);

	printf("File close \n");
	if((close(fd1)) < 0) {
		perror("Close failed");
		free(c);
		return;
	}

	printf("File creat function \n");
	fd2 = creat("abc.txt",S_IRWXU | S_IWUSR | S_IRGRP | S_IROTH);

	printf("File write function \n");
	length = write(fd2, c, length);

	if((close(fd2)) < 0) {
		perror("Close failed");
		free(c);
		return;
	}
	printf("Closed the fds \n");

	printf("Link example - Renaming abc.txt to def.txt \n");
	link("abc.txt","def.txt");
	printf("unlink example - Removing abc.txt\n");
	unlink("abc.txt");


}

