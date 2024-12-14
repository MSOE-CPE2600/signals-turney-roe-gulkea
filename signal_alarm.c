/**
 * File: signal_alarm.c
 * Modified by: Alex Roe-Gulke
 * 
 * Brief summary of program: Signal Alarm is called after 5 seconds of program run,
 * and a notification is printed to the console to confirm.
 * compile: gcc -o signal_alarm signal_alarm.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

//signal handler
void handle_signal() {
    printf("Received a signal\n");
    exit(1);
}

int main() {
    //create signal reciever
    signal(SIGALRM, handle_signal);
    //send sigalarm in 5 sec
    alarm(5);
    //wait for signal
    while(1) {
        printf("Sleeping\n");
        sleep(1);
    }
    return 0;
}
