/**
student number = 22463204
student name = al-ameen adedeji
acknowledgement of the DCU Academic Integrity Policy
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <unistd.h>
#include "external_commands.h"

/**
 * Execute an external command.
 * 
 * @param args Array of strings containing the command and its arguments.
 * @param input_file Filename for input redirection (if any).
 * @param output_file Filename for output redirection (if any).
 * @param append Flag indicating whether to append to the output file.
 * @param background Flag indicating whether to run the command in background.
 */
void execute_external_command(char **args, char *input_file, char *output_file, bool append, bool background) {
    pid_t pid = fork(); // Fork a new process
    if (pid < 0) { // Fork failed
        perror("Fork failed");
        exit(1);
    } 
    else if (pid == 0) { // Child process
        // Set the environment for the child process
        setenv("parent", "/myshell", 1);
        
        //freeopen and stream management from week 04/05 lab
        
        // If input redirection is requested, open the input file
        if (input_file != NULL) {
            if (freopen(input_file, "r", stdin) == NULL) {
                perror("Input redirection failed");
                exit(1);
            }
        }

        // If output redirection is requested, open the output file
        if (output_file != NULL) {
            if (append) {
                if (freopen(output_file, "a", stdout) == NULL) {
                    perror("Output redirection (append) failed");
                    exit(1);
                }
            } else {
                if (freopen(output_file, "w", stdout) == NULL) {
                    perror("Output redirection (overwrite) failed");
                    exit(1);
                }
            }
        }

        // Execute the command
        if (execvp(args[0], args) == -1) {
            perror("Execution failed");
            exit(1);
        }
    } else { // Parent process
        if (!background) {
            // Wait for the child process to complete
            int status;
            if (waitpid(pid, &status, 0) == -1) {
                perror("Waitpid failed");
                exit(1);
            }
        }
    }
}

