##                                                                                  myShell User Manual

## Introduction

        Welcome to myShell, a user-friendly UNIX-like shell designed to facilitate command execution, I/O redirection, background process management, and environment interaction. 
        This manual aims to provide guidance on myShell's functionality and usage.

## Definitions 
        internal commands: 
            cd, clr, dir, environ, echo, help, pause, quit.
        external commands: 
            any valid shell command that isnt an internal command.

## Executing Commands
        To execute commands in external commands in myShell, enter the desired external command followed by any necessary arguments and press Enter. For example:

                `ls -l`

        This command lists the contents of the current directory in a detailed format.

        Internal Commands:
            cd : 
                syntax : `cd [/path/to/directory]`, Description: allows the user to change from one directory to another.
            clr : 
                syntax : `clr`, Description: clears any immediate text from the command line.
            dir :
                syntax : `dir`, , Description: lists all files or directories in a directory including private/secret files and shows details like permissions.
            environ : 
                syntax : `environ`, Description: lists out the environment information of whatever environment the shell is currently being used in.
            echo : 
                syntax : `echo [args to be echoed]` , Description: prints out text to stdout or to a file if specified.
            help : 
                syntax : `help`, Description: Displays the use manual on the command line. 
            pause : 
                syntax : `pause`, Description: puts a pause on the myShell programme foreground execution and will only continue the shell upon pressing enter.
            quit : 
                syntax : `quit`, description: allows the user to change from one directory to another.

## I/O Redirection

        Description: 
            Input/Output redirection allows changing the source or destination of command input or output, enabling interaction with files or other processes.
            When you typically run a shell command like echo or cat through the command line/standard input, the output is typically put out onto standard output/the command line.
            Using input/output redirection we can bypass this behavior and, rather than put the result onto the command line we can store it in a file 
            or even read our input for this program from a file rather than our standard input using input redirection,
            This can allow us greater flexibility in what we can do with multiple files being able to store and use output from different files.
        
        Syntax: 
            Use `<` to redirect input from a file, `>` to redirect output to a file, and `>>` to append output to a file.

        Usage: 
            It's useful for manipulating command input and output, enabling automation and scripting tasks.

        Example:
            - To redirect input from a file, use the `<` symbol followed by the filename. For example:

                    `sort < input.txt`

            This command sorts the contents of the file 'input.txt'.

            - To redirect output to a file, utilize the `>` symbol followed by the filename. For example:

                    `ls > output.txt`

            This command lists the directory contents and saves the output to 'output.txt.

            - Appending output to a file is achievable with the `>>` symbol. For example:

                    `echo "Hello, world!" >> output.txt`

            This command appends the text "Hello, world!" to `output.txt` without removing the previous contents of the file.

## Background Execution
        Only available for external commands 
        
        Description: 
            Running a command in the background allows it to execute independently of the shell, enabling concurrent execution of multiple commands,
            in contrast to foreground execution which refers to running a command that holds the shell prompt until the command completes its execution.
            Background execution works by allowing a command or process to run semi-independently of the shell's main process. 
            When a command is executed in the background, it's initiated in a separate process from the one enabling the shell, 
            enabling the user to continue interacting with the shell while the command runs.
        
        Syntax: 
            Append & at the end of a command to execute it in the background. 
            `command [&]`

        Usage: 
            Users can continue working within the shell while long-running tasks execute in the background, improving overall productivity.
            It can allow users to run multiple tasks simultaneously without waiting for each command to finish before executing the next one.
            Facilitates the automation of repetitive tasks or batch processing, freeing up the user to perform other activities.
        
        Example: 
            `sleep 10 &`
            
            runs the sleep command for 10 seconds in the background, allowing the shell to remain responsive for other tasks.

## myShell Environment

        Description: 
            The program environment in myShell refers to the collection of variables and settings that influence the behavior of commands and programs executed within the shell.
            Environment variables are dynamic named values that define the operating environment for processes and programs. 
            These variables are stored within myshells environment and can be accessed by both the shell and the programs it runs.
            Examples of environment variables include PATH, HOME, USER, and SHELL.
            Each shell instance maintains its own environment, which consists of environment variables and settings specific to that shell session.
            When a new shell is created, it inherits the environment of its parent shell, 
            but modifications made to the environment within the child shell do not affect the parent shell's environment.

        Syntax: 
            Environment variables can be set or modified using the setenv command, followed by the variable name and its value.
            `setenv [option]`
        Usage: 
            Environment variables are used to store information such as system paths, user preferences, and configuration settings.
            They provide a way to customize the behavior of commands and programs within myShell.
            Environment variables play a crucial role in customizing the user experience and configuring the behavior of myShell and its underlying components.

        Example:

            `setenv PATH /bin:/usr/bin` sets the search path for executable files.
            `setenv EDITOR vim` sets the default text editor to Vim.
            `setenv SHELL /bin/bash` changes the default shell to Bash.
            View current environment variables using the `environ` command. 
            For example:

                `environ`

            This command displays system and user-defined environment variables.

## References

1. Silberschatz, A., Galvin, P.B., & Gagne, G. (2018). *Operating System Concepts.* Wiley. (chapters 3-5, 13-15)
2. Tanenbaum, A. S., & Bos, H. (2015). Modern Operating Systems. 
3. Robbins, A., & Robbins, A. (2005). Learning the bash Shell: Unix Shell Programming.
4. Stallings, W. (2014). *Operating Systems: Internals and Design Principles.* Pearson.
5. Fletcher, S., & Mangan, M. (2018). Process Management in Modern Operating Systems: A Comparative Analysis.
6. Wang, L., & Zhang, S. (2019). A Survey of Parallel and Distributed Shell Scripting Techniques. Journal of Parallel and Distributed Computing

## me:
student number = 22463204
student name = al-ameen adedeji
acknowledgement of the DCU Academic Integrity Policy
