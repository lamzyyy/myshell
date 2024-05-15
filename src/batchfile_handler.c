/**
student number = 22463204
student name = al-ameen adedeji
acknowledgement of the DCU Academic Integrity Policy
:set nonumber 
*/
#include <stdio.h>
#include <stdlib.h>
#include "batchfile_handler.h"

/**
 * Open the input file for batch processing.
 * 
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line arguments.
 * @return FILE pointer to the opened input file.
 */
FILE *open_input_file(int argc, char **argv) {
    FILE *input;

    // Check if a batch file is provided as a command-line argument
    if (argc > 1) {
        // Open the batch file for reading
        input = fopen(argv[1], "r");
        if (!input) {
            // Print error message if file opening fails
            perror("Error opening file");
            exit(1);
        }
    } else {
        // If no batch file provided, read from standard input
        input = stdin;
    }

    return input;
}

