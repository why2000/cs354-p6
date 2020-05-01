#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<time.h>
#include<string.h>

unsigned alrm_time = 3;
unsigned counter = 0;

void handler_SIGINT(int sig){
    printf("\nSIGINT received.\n");
    printf("SIGUSR1 was received %u times. Exiting now.\n", counter);
    exit(0);
}


void handler_SIGUSR1(int sig){
    printf("SIGUSR1 caught!\n");
    counter++;
}


void handler_SIGALRM(int sig){
    time_t t = time(NULL);
    struct tm* lt = localtime(&t);
    printf("PID: %d | Current Time: %s", getpid(), asctime(lt));
    alarm(alrm_time);
    return;
}


int main(int argc, char** argv){
    printf("Pid and time will be printed every 3 seconds.\n");
    printf("Enter ^C to end the program.\n");
    alarm(alrm_time);
    struct sigaction actalrm, actusr1, actint;
    // for SIGALRM
    memset(&actalrm, 0, sizeof(actalrm));
    actalrm.sa_handler = handler_SIGALRM;
    if(sigaction(SIGALRM, &actalrm, NULL)<0){
        perror("Error binding sigaction for SIGALRM!\n");
        return 1;
    }
    // for SIGUSR1
    memset(&actusr1, 0, sizeof(actusr1));
    actusr1.sa_handler = handler_SIGUSR1;
    if(sigaction(SIGUSR1, &actusr1, NULL)<0){
        perror("Error binding sigaction for SIGUSR1!\n");
    }
    // for SIGINT
    memset(&actint, 0, sizeof(actint));
    actint.sa_handler = handler_SIGINT;
    if(sigaction(SIGINT, &actint, NULL)<0){
        perror("Error binding sigaction for SIGINT!\n");
    }
    while(1){}
    return 0;
}
