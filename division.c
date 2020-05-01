#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<time.h>
#include<string.h>
int counter;

void handler_SIGINT(int sig){
    printf("Total number of operations successfully completed: %d\n", counter);
    exit(0);
}

void handler_SIGFPE(int sig){
    printf("Error: a division by 0 operation was attempted.\n");
    printf("Total number of operations completed successfully: %d\n", counter);
    exit(0);
}

int main(int argc, char** argv){
    while(1){
        char buf[100];
        int num1, num2, res;
        printf("Enter first integer: ");
        fgets(buf, 100, stdin);
        num1 = atoi(buf);
        printf("Enter second integer: ");
        fgets(buf, 100, stdin);
        num2 = atoi(buf);
        res = num1/num2;
        printf("%s / %s is %d with a remainder of %d",\
        num1, num2, res, num1 - num2*res);
        return 0;
    }
}