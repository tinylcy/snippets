#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define STDIOFD 0
#define STDOUTFD 1
#define MAXBUF 8192
/*
 * tee：从标准输入中读取数据，直至文件结尾，随后将数据写入标准
 *      输出和命令行参数所指定的文件。
 *      默认情况下，若已存在与命令行参数指定的文件同名的文件，
 *      tee命令会将其覆盖。如文件已存在，使用 -a 命令行选项(tee -a file)
 *      在文件结尾处追加数据。
 */
int main(int argc, char *args[]) {
	if(argc != 2 && argc != 3) {
		perror("usage: ./tee [-a] file");
		exit(EXIT_FAILURE);
	}
	if(argc == 3 && strcmp(args[2], "-a") != 0) {
		perror("usage: ./tee [-a] file");
		exit(EXIT_FAILURE);
	}

	int fd, num_read, num_write, ret;
	char buf[MAXBUF];
	if(strcmp(args[1], "-a") == 0) {
		fd = open(args[2], O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	} else {
		fd = open(args[1], O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	}
	if(fd == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}

	while((num_read = read(STDIOFD, buf, MAXBUF)) > 0) {
		num_write = write(STDOUTFD, buf, num_read);
		if(num_write == -1) {
			perror("write");
			exit(EXIT_FAILURE);
		}
		num_write = write(fd, buf, num_read);
		if(num_write == -1) {
			perror("write");
			exit(EXIT_FAILURE);
		}
	}
	
	ret = close(fd);
	if(ret == -1) {
		perror("close");
		exit(EXIT_FAILURE);
	}

	return 0;
	
}
