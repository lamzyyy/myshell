/**
student number = 22463204
student name = al-ameen adedeji
acknowledgement of the DCU Academic Integrity Policy
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>
#include "redirect_backgroundExec.h"

/**
 * Handle input/output redirection and background execution flags.
 * 
 * @param args Array of strings containing the command and its arguments.
 * @param input_file Pointer to the input file name (will be set to NULL if no input redirection).
 * @param output_file Pointer to the output file name (will be set to NULL if no output redirection).
 * @param append Pointer to the flag indicating whether to append to the output file.
 * @param background Pointer to the flag indicating whether to run the command in background.
 */
void handle_redirect_and_background(char **args, char **input_file, char **output_file, bool *append, bool *background) {
    *input_file = NULL;
    *output_file = NULL;
    *append = false;
    *background = false;

    // Loop through the command arguments
    for (int i = 0; args[i] != NULL; i++) {
        if (strcmp(args[i], "<") == 0) { // Input redirection symbol found
            *input_file = args[i + 1]; // Set input file name
            args[i] = NULL; // Terminate args at the redirection symbol
        } 
        else if (strcmp(args[i], ">") == 0) { // Output redirection symbol found
            *output_file = args[i + 1]; // Set output file name
            args[i] = NULL; 
            *append = false; 
        } 
        else if (strcmp(args[i], ">>") == 0) { // Output append redirection symbol found
            *output_file = args[i + 1]; 
            args[i] = NULL; 
            *append = true; // Set append flag to true
        } 
        else if (strcmp(args[i], "&") == 0) { // Background execution symbol found
            *background = true; // Set background flag
            args[i] = NULL; // Remove '&' from args
        }
    }
}

