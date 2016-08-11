/*
 * who2.c - read /etc/utmp and list info therein
 *        - suppresses empty records
 *        - forrmats time nicely
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <utmp.h>
#include <fcntl.h>
#include <time.h>

void showtime(long);
void show_info(struct utmp *);

int main() {
	struct utmp utbuf; /*read info into here*/
	int utmpfd;
	if((utmpfd = open(UTMP_FILE, O_RDONLY)) == -1) {
		perror(UTMP_FILE);
		exit(1);
	}

	while(read(utmpfd, &utbuf, sizeof(utbuf)) == sizeof(utbuf)) {
		show_info(&utbuf);
	}
	close(utmpfd);
	return 0;
}

/*
 * show_info()
 *			
 * display the contents of the utmp struct
 * in human readable form
 * display nothing if record has no user name
 */
void show_info(struct utmp *utbufp) {
	if(utbufp->ut_type != USER_PROCESS) {
		return;
	}
	printf("%-8.8s", utbufp->ut_name);
	printf(" ");
	printf("%-8.8s", utbufp->ut_line);
	printf(" ");
	showtime(utbufp->ut_time);
#ifdef SHOWHOST
	if(utbufp->ut_host[0] != '\0') {
		printf("(%s)", utbufp->ut_host);
	}
#endif
	printf("\n");
}

/*
 * showtime()
 * display time in a format fit for human consumption
 * uses ctime to build a string then picks parts out of it
 */
void showtime(long timeval) {
	char *cp;
	cp = ctime(&timeval);
	printf("%12.12s", cp + 4); /*pick 12 chars from pos 4*/
}

