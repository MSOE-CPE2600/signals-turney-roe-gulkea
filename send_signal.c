/**
 * File: send_singal.c
 * Modified by: Alex Roe-Gulke
 * 
 * Brief summary of program: Sends signal and random value to other terminal
 * compile: gcc -o send_signal send_signal.c
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    //check for arguements
    if (argc != 2) {
        printf("Incorrect format, value and pid required.");
        return 1;
    }
    //check for child process or invalid process
    int pid = atoi(argv[1]);
    if (pid <= 0) {
        fprintf(stderr, "Invalid pid");
        return 1;
    }
    //set up a value to send
    union sigval value;
    srand(time(NULL));
    value.sival_int = rand();
    //sigqueue to send signal
    if (sigqueue(pid, SIGUSR1, value) == -1) {
        perror("sigqueue");
        return 1;
    }

    printf("Sent Signal, Value: %d\n", value.sival_int);

    return 0;
}
