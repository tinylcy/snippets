#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* replaceBlank(char *string);

int main() {

    char string[] = "we are happy";
    char *new_string = NULL;

    new_string = replaceBlank(string);

    printf("%s\n", new_string);

    return 0;
}

char* replaceBlank(char *string) {
    int length = 0;        /*字符串的总长度*/
    int num_of_blank = 0;        /*空格个数*/

    int i = 0;
    for(i = 0; string[i] != '\0'; i++) {
        if(string[i] == ' ') {
            num_of_blank++;
        }
        length++;
    }

    int new_length = length + 2 * num_of_blank;

    char *new_string = (char*)malloc(new_length * sizeof(char*));
    memset(new_string, '\0', new_length);

    char *p1 = &string[length - 1];
    char *p2 = &new_string[new_length - 1];

    while(--length >= 0) {
        if(*p1 == ' ') {
            *p2 = '0'; p2--;
            *p2 = '2'; p2--;
            *p2 = '%'; p2--;
        }else {
            *p2 = *p1; p2--;
        }
        p1--;
    }

    new_string[new_length] = '\0';

    return new_string;

}
