/**
student number = 22463204
student name = al-ameen adedeji
acknowledgement of the DCU Academic Integrity Policy
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "internal_commands.h"

extern char **environ; // External variable for environment
extern int MAX_BUFFER; // External variable for environment
/**
 * Handle the 'environ' command, which prints the current environment variables.
 * 
 * @param output_file Name of the file to which the output will be redirected.
 * @param append Flag indicating whether to append to the output file if it exists.
 */
void environ_handler(char *output_file, bool append) {
    int i = 0;
    FILE *output = stdout;

    // Open the specified output file for writing or appending
    if (output_file != NULL) {
        if (append) {
            output = fopen(output_file, "a");
        } else {
            output = fopen(output_file, "w");
        }
        if (!output) {
            perror("Error opening output file");
            return;
        }
    }

    // Iterate through the environment variables and print them
    while (environ[i] != NULL) {
        fprintf(output, "%s\n", environ[i]);
        i++;
    }

    // Close the output file if it was opened
    if (output != stdout) {
        fclose(output);
    }
}

/**
 * Handle the 'clear' command, which clears the terminal screen.
 */
void clear_handler() {
    // Execute the 'clear' command using the system function
    if (system("clear") == -1) {
        perror("Clear command failed");
    }
}

/**
 * Handle the 'dir' command, which lists the contents of a directory.
 * 
 * @param directory Name of the directory to list. If NULL, lists the current directory.
 * @param output_file Name of the file to which the output will be redirected.
 * @param append Flag indicating whether to append to the output file if it exists.
 */
void dir_handler(char *directory, char *output_file, bool append) {
    FILE *output = stdout;

    // Open the specified output file for writing or appending
    if (output_file != NULL) {
        if (append) {
            output = fopen(output_file, "a");
        } else {
            output = fopen(output_file, "w");
        }
        if (!output) {
            perror("Error opening output file");
            return;
        }
    }

    // Build the ls command with the specified directory
    char command[MAX_BUFFER];
    if (directory != NULL) {
        snprintf(command, sizeof(command), "ls -al %s", directory);//safely add required command to the 'command' buffer with a given directory
    } else {
        snprintf(command, sizeof(command), "ls -al");
    }

    // Open a pipe to execute the command and read its output
    FILE *ls_output = popen(command, "r");
    if (!ls_output) {
        perror("Error executing ls command");
        if (output != stdout) {
            fclose(output);
        }
        return;
    }

    // Read from the command output and write it to the output file
    char buffer[MAX_BUFFER];
    while (fgets(buffer, sizeof(buffer), ls_output) != NULL) {
        fprintf(output, "%s", buffer);
    }

    // Close the pipe and the output file if it was opened
    pclose(ls_output);
    if (output != stdout) {
        fclose(output);
    }
}

/**
 * Handle the 'echo' command, which prints its arguments to the console.
 * 
 * @param args Array of arguments to be printed.
 * @param output_file Name of the file to which the output will be redirected.
 * @param append Flag indicating whether to append to the output file if it exists.
 */
void echo_handler(char **args, char *output_file, bool append) {
    FILE *output = stdout;

    // Open the specified output file for writing or appending
    if (output_file != NULL) {
        if (append) {
            output = fopen(output_file, "a");
        } else {
            output = fopen(output_file, "w");
        }
        if (!output) {
            perror("Error opening output file");
            return;
        }
    }

    // Print each argument to the output file or stdout
    bool first_arg = true;
    args++; // Skip the "echo" command itself
    while (*args != NULL) {
        if (!first_arg) {
            fputc(' ', output);
        } // Print space between arguments
        fprintf(output, "%s", *args);
        first_arg = false;
        args++;
    }
    fputc('\n', output); // New line after printing all arguments

    // Close the output file if it was opened
    if (output != stdout) {
        fclose(output);
    }
}

/**
 * Handle the 'cd' command, which changes the current working directory.
 * 
 * @param dir Directory to change to. If NULL, prints the current directory.
 */
void cd_handler(char *dir) {
    char cwd[MAX_BUFFER];
    
    // If no directory specified, print the current directory
    if (dir == NULL) {
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            printf("Current directory: %s\n", cwd);
        } else {
            perror("getcwd() error");
        }
    }
    // Change to the specified directory
    else if (getcwd(cwd, sizeof(cwd)) != NULL) {
        char full_path[MAX_BUFFER];
        snprintf(full_path, sizeof(full_path), "%s/%s", cwd, dir);//handling the case where you get the full path and reletive path
        if (chdir(full_path) == 0) {
            setenv("PWD", full_path, 1);
        } else {
            perror("chdir failed");
        }
    }
}

/**
 * Handle the 'pause' command, which waits for user input before continuing.
 */
void pause_handler() {
    printf("Press Enter to continue...\n");
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}
void help_handler(){
    system("more ../manual/readme.md");// display the manual
}

