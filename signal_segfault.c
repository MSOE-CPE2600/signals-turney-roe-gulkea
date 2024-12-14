/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by: Alex Roe-Gulke
 * 
 * Brief summary of modifications: Notes when the program receives a seg-fault,
 * then continues the program rther than crashing.
 * compile: gcc -o signal_segfault signal_segfault.c
 */


#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void handle_signal() {
    printf("Received a signal\n");
}

int main (int argc, char* argv[]) {

    // Signal Prep
    signal(SIGSEGV, handle_signal);

    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}