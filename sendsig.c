#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<time.h>
#include<string.h>


int main(int argc, char** argv){
    // checking cmdline arg
    if(argc != 2) print("Usage: <signal type> <pid>\n");
    pid_t pid;
    if((pid = atoi(argv[2])) == 0 && argv[2][0] != '0'){
        print("Usage: <signal type> <pid>\n");
    }
    if(strcmp(argv[0], "-u")){
        kill(pid, SIGUSR1);
    }
    else if (strcmp(argv[0], "-i")) {
        kill(pid, SIGINT);
    }
    else print("Usage: <signal type> <pid>\n");
    return 0;
}