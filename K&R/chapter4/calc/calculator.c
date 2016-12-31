#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define MAXVAL 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);

int getch(void);
void ungetch(int);

int sp = 0;
double val[MAXOP];

int main(void) {
	int type;
	double op2;
	char s[MAXOP];

	while((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '*':
				push(pop() * pop());
				break;
			case '/':
				op2 = pop();
				push(pop() / op2);
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("error: unkoown command %s\n", s);
				break;
		}
	}

	return 0;
}

void push(double f) {
	if(sp < MAXVAL) {
		val[sp++] = f;
	} else {
		printf("error: stack full, cam't push %g\n", f);
	}
}

double pop(void) {
	if(sp > 0) {
		return val[--sp];
	} else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getop(char s[]) {
	int i, c;
	while((s[0] = c = getch()) == ' ' || c == '\t') {
		;
	}
	s[1] = '\0';
	if(!isdigit(c) && c != '.') {
		return c;
	}
	i = 0;
	if(isdigit(c)) {
		while(isdigit(s[++i] = c = getch())) {
			;
		}
	}
	if(c == '.') {
		while(isdigit(s[++i] = c = getch())) {
			;
		}
	}
	s[i] = '\0';
	if(c != EOF) {
		ungetch(c);
	}
	return NUMBER;
}

int getch(void) {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
	if(bufp < BUFSIZE) {
		buf[bufp++] = c;
	} else {
		printf("ungetch: top many characters\n");
	}
}

