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
	if ((fd1 = open("/home/arun/C/syscalls/systemcalls/README.md", O_RDWR | O_CREAT | O_APPEND, 0644)) < 0) {
		perror("READ ME");
		free(c);
		return;
	}

	length = read(fd1,c,100);
	printf("Called the read() %d\n",length);
	c[length] ='\0';
	printf("Data in the file is %s",c);

	l = lseek(fd1, 0, SEEK_CUR);
	printf("Current lseek %d \n",l);

	length = write(fd1, c, length);

	if((close(fd1)) < 0) {
		perror("Close failed");
		free(c);
		return;
	}
	printf("Closed the fds \n");
}

