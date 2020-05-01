///////////////////////////////////////////////////////////////////////////////
// Main File:        sendsig.c
// This File:        sendsig.c
// Other Files:      intdate.c, division.c (both irrelative to this file)
// Semester:         CS 354 Spring 2020
//
// Author:           Hanyuan Wu
// Email:            hwu384@wisc.edu
// CS Login:         hanyuan
//
/////////////////////////// OTHER SOURCES OF HELP /////////////////////////////
//                   fully acknowledge and credit all sources of help,
//                   other than Instructors and TAs.
//
// Persons:          Identify persons by name, relationship to you, and email.
//                   Describe in detail the the ideas and help they provided.
//
// Online sources:   avoid web searches to solve your problems, but if you do
//                   search, be sure to include Web URLs and description of
//                   of any information you find.
////////////////////////////////////////////////////////////////////////////////
//
// Copyright 2013,2019-2020
// Posting or sharing this file is prohibited, including any changes/additions.
//
////////////////////////////////////////////////////////////////////////////////

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
