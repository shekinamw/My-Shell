/*******************
AUTHORS: 
SHEKINA HIEN 100807845
NAFTANAN MAMO 100822222

************************/

// utility.c
// This file will have the implementation of the commands.

#include "myshell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h> // For directory operations
#include <sys/types.h> // For opendir, readdir, closedir
extern char **environ;// The 'environ' variable is a global variable that holds the environment variables
#ifdef _WIN32
    #define CLEAR_SCREEN "cls"
#else
    #define CLEAR_SCREEN "clear"
#endif

/* Function to change the current working directory */

void change_directory(char *path) {
    // Check if the path argument is NULL, which implies no specific directory was provided
    if (path == NULL) {
        // Create a buffer to store the current working directory path
        char cwd[1024];

        // Use getcwd to get the current working directory.
        // getcwd fills the array 'cwd' with the absolute pathname of the current working directory.
        // If the function succeeds, the cwd array contains this pathname and NULL is not returned.
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            // If successful, print the current working directory to the user
            printf("%s\n", cwd);
        } else {
            // If getcwd fails, use perror to print an error message.
            // perror produces a message on standard error describing the last error encountered during a call to a system or library function.
            perror("getcwd() error");
        }
    } else {
        // If a path is provided, try changing the directory to the specified path using chdir
        // chdir changes the current working directory of the calling process to the directory specified in path.

        // If chdir returns a non-zero value, it indicates an error occurred (like if the directory does not exist).
        if (chdir(path) != 0) {
            // In case of an error, use perror to print the error message.
            perror("myshell");
        }
    }
}


// Function to clear the screen
void clear() {
    system("clear");
}

// Function to print all the environment variables
void print_env() {
    extern char **environ; // Access to the environment variables
    // Loop through each string in the 'environ' array
    for (char **current = environ; *current; current++) {
        // Print the current environment variable
        printf("%s\n", *current);
    }
}

// Function to list contents of the directory
void list_directory_contents(const char *directory) {
    DIR *dir;
    struct dirent *entry;

    // Open the directory
    dir = opendir(directory);

    // Check if directory exists
    if (dir != NULL) {
        // Read directory contents
        while ((entry = readdir(dir)) != NULL) {
            // Print the item
            printf("%s\n", entry->d_name);
        }
        closedir(dir);
    } else {
        // Directory does not exist
        printf("Directory does not exist.\n");
    }
}

// Function to display user manual
void display_user_manual() {
    printf("User Manual:\n");
    printf("1. 'cls': Clear the screen\n");
    printf("2. 'environ': List environment variables\n");
    printf("3. 'dir <directory>': List contents of the directory\n");
    printf("4. 'echo <comment>': Echo a comment\n");
    printf("5. 'help': Display this user manual\n");
    printf("6. 'pause': Pause operation until 'Enter' is pressed\n");
    printf("7. 'quit': Quit the shell\n");
}

// Function to pause operation until 'Enter' is pressed
void pause_operation() {
    printf("System Paused... Press Enter to continue...");
    while (getchar() != '\n');
}
