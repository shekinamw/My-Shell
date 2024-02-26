**MyShell User Manual**

**Operation and Commands:**

MyShell is a command-line shell program providing users with internal and external commands.

1. **Internal Commands:**

    - **cd [directory]:** Change the current directory.
    
    - **cls:** Clear the screen.
    
    - **environ:** Print environment variables.
    
    - **dir [directory]:** List directory contents.
    
    - **echo [comment]:** Print a comment.
    
    - **help:** Display user manual.
    
    - **pause:** Pause shell operation.
    
    - **quit:** Exit the shell.

2. **External Commands:**

    Execute any external program.

**Handling Program Invocation:**

- **Without Command Line Argument:**
    
    Enter interactive mode, prompting user for commands.

- **With Command Line Argument (Batch Mode):**
    
    Execute commands from specified file sequentially.

**File-Based Command Execution:**

In batch mode, execute commands from a file line by line.

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

