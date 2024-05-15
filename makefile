#student number = 22463204
#student name = al-ameen adedeji
#acknowledgement of the DCU Academic Integrity Policy
CC = gcc

# Compilation flags
CFLAGS = -Wall

# Source files
SRCS = src/myShell.c src/batchfile_handler.c src/external_commands.c src/internal_commands.c src/redirect_backgroundExec.c src/utilities.c

# Header files
HDRS = src/batchfile_handler.h src/external_commands.h src/internal_commands.h src/redirect_backgroundExec.h src/utilities.h

# Target executable
TARGET = bin/myshell

# Rule to build the target executable
$(TARGET): $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

# Clean rule
clean:
	rm -f $(TARGET)

