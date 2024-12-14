/**
 * @file signal_handler.c
 * @brief Sets a signal handler for SIGINT, the handler prints a message and then quits
 */

/**
 * Modified by: Alex Roe-Gulke
 * 
 * Brief summary of modifications:
 * the signal being handled is now SIGKILL, so the 
 * program terminates before attempting to handle the signal.
 * compile: gcc -o signal_handler signal_handler.c
 */


#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Signal handler for SIGINT - prints a message and exits
 */
void handle_signal() {
    printf("Received a signal\n");
    exit(1);
}

int main() {

    // Register for the signal
    signal(SIGKILL, handle_signal);

    // Wait until a signal is received
    while(1) {
        printf("Sleeping\n");
        sleep(1);
    }

    return 0;
}