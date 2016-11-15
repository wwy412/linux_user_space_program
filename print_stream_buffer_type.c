#include "stdio.h"
#include "unistd.h"
#include "fcntl.h"

void pr_stdio(const char *, FILE *);

int main(void)
{
        FILE *fp;

        fputs("enter any character\n", stderr);
        if(getchar() == EOF){
                fputs("getchar error\n", stderr);
                exit(0);
        }

        fputs("one line to standard error\n", stdout);
        pr_stdio("stdin", stdin);
        pr_stdio("stdout", stdout);
        pr_stdio("stderr", stderr);

        if((fp = fopen("/etc/motd", "r")) == NULL){
                printf("open motd error\n");
                exit(0);
        }

        if(getc(fp) == EOF){
                printf("motd is empty\n");
                exit(0);
        }

        pr_stdio("/etc/motd", fp);
        exit(0);
}

void pr_stdio(const char *name , FILE *fp)
{
        printf("stream = %s, ", name);
        if(fp->_flags & _IONBF) printf("unbuffered\n");
        else if(fp->_flags & _IOLBF) printf("line buffered\n");
        else printf("full buffered\n");

// printf(", buffer size = %d\n", fp->_bufsize);
}

