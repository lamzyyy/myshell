/**
student number = 22463204
student name = al-ameen adedeji
acknowledgement of the DCU Academic Integrity Policy
*/
#ifndef INTERNAL_COMMANDS_H 
#define INTERNAL_COMMANDS_H 

void cd_handler(char *dir);
void clear_handler();
void dir_handler(char *directory, char *output_file, bool append);
void echo_handler(char **args, char *output_file, bool append);
void environ_handler(char *output_file, bool append);
void pause_handler();
void help_handler();
#endif /* INTERNAL_COMMANDS_H */
