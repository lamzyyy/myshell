/**
student number = 22463204
student name = al-ameen adedeji
acknowledgement of the DCU Academic Integrity Policy
*/
#ifndef UTILITIES_H
#define UTILITIES_H

extern const int MAX_BUFFER;
extern char **argv;
extern const int MAX_ARGS;
extern const char* SEPARATORS;

void generate_prompt(char buf[1024], int buf_size, char* prompt);

void set_my_env(char * arg);
#endif /* UTILITIES_H */


