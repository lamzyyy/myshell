/**
student number = 22463204
student name = al-ameen adedeji
acknowledgement of the DCU Academic Integrity Policy
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>
#include <sys/wait.h> // For waitpid
#include "utilities.h"
#include "batchfile_handler.h"
#include "redirect_backgroundExec.h"
#include "internal_commands.h"
#include "external_commands.h"

int main(int argc, char **argv) {
    char buf[MAX_BUFFER];       // line buffer
    char *args[MAX_ARGS];       // pointers to arg strings
    char **arg;                 // working pointer thru args
    char *prompt = NULL;        // shell prompt
    FILE *input;
    char *input_file = NULL;
    char *output_file = NULL;
    bool append = false;
    bool background = false;

    /* Set the parent environment variable */
    input = open_input_file(argc, argv); // Open input file if provided
    set_my_env(argv[0]); // Set environment variables

    while (!feof(input)) { // Loop until end of file is reached
        generate_prompt(buf, sizeof(buf), prompt); // Generate shell prompt
        if (fgets(buf, MAX_BUFFER, input)) { // Read a line from input
            /** Tokenize the input into args array 
                got this code from the 04/05 lab
            */
            arg = args;
            *arg++ = strtok(buf, SEPARATORS); // Tokenize input
            while ((*arg++ = strtok(NULL, SEPARATORS))); // Tokenize remaining arguments

            /* Last entry will be NULL */
            if (args[0]) { // If there's anything there
                handle_redirect_and_background(args, &input_file, &output_file, &append, &background); // Handle I/O redirection and background execution

                if (!strcmp(args[0], "clr")) { // Internal command: clear
                    clear_handler(); // Clear the terminal screen
                    continue;
                }
                if (!strcmp(args[0], "dir")) { // Internal command: dir
                    dir_handler(args[1], output_file, append); // List directory contents
                    continue;
                }
                if (!strcmp(args[0], "echo")) { // Internal command: echo
                    echo_handler(args, output_file, append); // Print arguments
                    continue;
                }
                if (!strcmp(args[0], "environ")) { // Internal command: environ
                    environ_handler(output_file, append); // Print environment variables
                    continue;
                }
                if (!strcmp(args[0], "help")) { // Internal command: help
                    help_handler();// display the user manual
                    continue;
                }
                if (!strcmp(args[0], "pause")) { // Internal command: pause
                    pause_handler(); // Wait for user input
                    continue;
                }
                if (!strcmp(args[0], "cd")) { // Internal command: cd
                    cd_handler(args[1]); // Change directory
                    continue;
                }
                if (!strcmp(args[0], "quit")) { // Internal command: quit
                    exit(0); // Exit the shell
                }
                /* Execute other commands as external programs */
                else {
                    execute_external_command(args, input_file, output_file, append, background); // Execute external command
                }
            }
        }
    }

    if (input != stdin) { // Close input file if opened
        fclose(input);
    }

    return 0;
}

