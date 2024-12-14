/**
 * File: recv_signal.c
 * Modified by: Alex Roe-Gulke
 * 
 * Brief summary of program: Recieves signals from other terminal
 * compile: gcc -o recv_signal recv_signal.c
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void handle_signal(int signum, siginfo_t *info, void *context) {
    printf("Signal recieved: %d, value %d\n", signum, info -> si_value.sival_int);
}

int main(void) {
    //pid print
    printf("pid of this Process: %d\n", getpid());
    //sigaction set-up
    struct sigaction sa;
    sa.sa_sigaction = handle_signal;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);
    //program waits
    while(1){
        sleep(1);
    }
    //ret
    return 0;
}
