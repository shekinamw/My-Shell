**MyShell User Manual**

**Description of Operation and Commands:**

MyShell is a simple command-line shell program that provides users with a set of commands for interacting with the system. It supports both internal commands (built-in functionalities) and external commands (executing programs).

1. **Internal Commands:**

    - **cd [directory]:** Change the current working directory to the specified directory.
    
    - **cls:** Clear the screen.
    
    - **environ:** Print all environment variables.
    
    - **dir [directory]:** List the contents of the specified directory. If no directory is provided, list the contents of the current directory.
    
    - **echo [comment]:** Print the provided comment.
    
    - **help:** Display the user manual.
    
    - **pause:** Pause the operation of the shell until the Enter key is pressed.
    
    - **quit:** Quit the shell.

2. **External Commands:**

    External commands are executed by the shell as child processes. These commands can be any executable programs available in the system.

**Description of Handling Program Invocation:**

MyShell can be invoked from the command line with or without a command line argument. 

- **Without Command Line Argument:**
    
    If no command line argument is provided, MyShell enters interactive mode. It prompts the user with "MyShell> " and waits for input from the standard input (keyboard). The user can enter commands interactively, and MyShell executes them accordingly until the user quits the shell.

- **With Command Line Argument (Batch Mode):**
    
    If MyShell is invoked with a command line argument (e.g., `myshell batchfile`), it enters batch mode. In this mode, MyShell reads commands from the specified batch file and executes them sequentially. When the end of the file is reached, the shell exits.

**Description of File-Based Command Execution:**

In batch mode, MyShell reads commands from a file and executes them one by one. This feature allows users to automate the execution of multiple commands without manual input. Each command should be on a separate line in the batch file.

**Example Batch File (batchfile):**
```
cd /path/to/directory
ls
echo Hello, World!
```

**Executing MyShell in Batch Mode:**
```
$ ./myshell batchfile
```

This will execute the commands in the `batchfile` sequentially: change directory to `/path/to/directory`, list the contents of the directory, and print "Hello, World!".

