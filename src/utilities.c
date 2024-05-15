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
#include "utilities.h"

// Define constants for maximum buffer size, maximum arguments, and separators
const int MAX_BUFFER = 1024;
const int MAX_ARGS = 64;
const char* SEPARATORS = " \t\n";
const int MAX_PROMPT_SIZE = MAX_BUFFER + 5;
const char* PROMPT_FORMAT = "%s ==> ";

/**
 * Generate a prompt string indicating the current directory.
 * 
 * @param buf Character array to store the current directory.
 * @param buf_size Size of the buffer for the current directory.
 * @param prompt Pointer to store the generated prompt string.
 */
void generate_prompt(char buf[MAX_BUFFER], int buf_size, char* prompt){
    // Get the current working directory
    if (getcwd(buf, buf_size) == NULL) {
        perror("Error getting current directory");
        exit(1);
    }

// Allocate memory for the prompt string
    prompt = malloc(sizeof(char) * (strlen(buf) + 6)); // Length of directory + 6 characters for " ==> "
    if (prompt == NULL) {
        perror("Error creating prompt");
        exit(1);
    }

    // Construct the prompt string
    snprintf(prompt, strlen(buf) + 6, "%s ==> ", buf);

    // Write the prompt to stdout
    fputs(prompt, stdout);

    // Free allocated memory for the prompt
    free(prompt);
    }

/**
 * Set environment variables for the shell.
 * 
 * @param arg1 Path to the shell executable.
 */
void set_my_env(char *arg1){
    // Set the environment variables
    setenv("parent", "/myshell", 1);
    setenv("SHELL", arg1, 1);
}

