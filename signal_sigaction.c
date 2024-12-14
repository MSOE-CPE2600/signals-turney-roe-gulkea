/**
 * File: signal_sigaction.c
 * Modified by: Alex Roe-Gulke
 * 
 * Brief summary of program: Utilizes sigaction to recieve a SIGUSR1 signal,
 * which causes the program to return it's sender's pid.
 * compile: gcc -o signal_sigaction signal_sigaction.c
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void handle_signal(int signum, siginfo_t *info, void *context) {
    //print sender pid
    printf("pid of Sender: %d", info -> si_pid); 
    printf("\n");
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
    }
    //ret
    return 0;
}
