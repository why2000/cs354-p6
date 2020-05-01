#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<time.h>
#include<string.h>


int main(int argc, char** argv){
    // checking cmdline arg
    if(argc != 3) {
        printf("Usage: <signal type> <pid>\n");
        exit(0);
    }
    pid_t pid;
    if((pid = atoi(argv[2])) == 0 && argv[2][0] != '0'){
        printf("Usage: <signal type> <pid>\n");
        exit(0);
    }
    if(strcmp(argv[1], "-u") == 0){
        kill(pid, SIGUSR1);
    }
    else if (strcmp(argv[1], "-i") == 0) {
        kill(pid, SIGINT);
    }
    else {
        printf("Usage: <signal type> <pid>\n");
        exit(0);
    }
    return 0;
}
