#include "myshell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// Function to execute the entered command
void execute_command(char *input) {
    char *token;
    char *delim = " \n";
    token = strtok(input, delim); // Tokenize the input

    // If the first token is a recognizable command
    if (token != NULL) {
        if (strcmp(token, "cd") == 0) {
            token = strtok(NULL, delim); // Get the next part of the input (directory path)
            change_directory(token); // Call the change_directory function
        } else if (strcmp(token, "cls") == 0) {
            clear(); // Call the clear function
        } else if (strcmp(token, "environ") == 0) {
            print_env(); // Call the print_env function
        } else if (strcmp(token, "dir") == 0) {
            token = strtok(NULL, delim); // Get the next part of the input (directory path)
            list_directory_contents(token); // Call the list_directory_contents function
        } else if (strcmp(token, "echo") == 0) {
            token = strtok(NULL, delim); // Get the next part of the input (comment)
            if (token != NULL) {
                printf("%s\n", token); // Print the comment
            } else {
                printf("echo: missing argument\n");
            }
        } else if (strcmp(token, "help") == 0) {
            display_user_manual(); // Call the display_user_manual function
        } else if (strcmp(token, "pause") == 0) {
            pause_operation(); // Call the pause_operation function
        } else if (strcmp(token, "quit") == 0) {
            exit(0); // Exit the shell
        } else {
            // External command, fork and execute
            pid_t pid = fork(); // Fork a child process
            if (pid == -1) {
                perror("fork"); // Error handling
                return;
            } else if (pid == 0) {
                // Child process
                // Set parent environment variable
                setenv("parent", "/path/to/myshell", 1); // Change "/path/to/myshell" to your actual path
                // Execute the command
                execvp(token, &token);
                // execvp only returns if an error occurs
                perror("exec");
                exit(EXIT_FAILURE);
            } else {
                // Parent process
                // Wait for the child process to finish
                int status;
                waitpid(pid, &status, 0);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    char input[1024]; // Buffer for user input

    // If the shell is invoked with a command line argument
    if (argc == 2) {
        // Open the batch file for reading
        FILE *batch_file = fopen(argv[1], "r");
        if (batch_file == NULL) {
            fprintf(stderr, "Error: Unable to open file %s\n", argv[1]);
            return 1; // Return error code
        }

        // Read commands from the file and execute them
        while (fgets(input, sizeof(input), batch_file) != NULL) {
            // Process the input command
            execute_command(input);
        }

        // Close the batch file
        fclose(batch_file);
    } else {
        // If no command line argument provided, solicit input from the user via a prompt
        while (1) {
            printf("MyShell> "); // Prompt for input
            if (fgets(input, sizeof(input), stdin) == NULL) {
                break; // Exit on EOF
            }
            // Remove trailing newline character
            input[strcspn(input, "\n")] = '\0';
            // Process the input command
            execute_command(input);
        }
    }

    return 0;
}
