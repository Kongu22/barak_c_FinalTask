#include "myFunction.h"
#include <stdlib.h>
#include <string.h>

char *getInputFromUser() {
    char tempBuf[101]; // Temporary buffer to hold input
    char *input;

    printf("Enter text (max 100 characters):\n");
    if(fgets(tempBuf, sizeof(tempBuf), stdin) != NULL) {
        size_t len = strlen(tempBuf);
        if (tempBuf[len - 1] == '\n') {
            tempBuf[len - 1] = '\0'; // Remove newline character
        }
        input = malloc(len);
        strcpy(input, tempBuf);
        return input;
    } else {
        return NULL; // fgets failed
    }
}

void blue(){

    printf("\033[0;34m");
}
void reset(){

     printf("\033[0m");
}

char **splitArgument(char *str)
{
    int size = 2; // Start with size for two pointers: one for the first token and one for NULL
    char **arguments = malloc(size * sizeof(char*));
    char *subStr = strtok(str, " "); // Initialize with the first token

    int index = 0;
    while (subStr != NULL)
    {
        arguments[index++] = subStr;
        if (index >= size - 1) { // Ensure there's space for the new token and NULL terminator
            size++;
            arguments = realloc(arguments, size * sizeof(char*));
        }
        subStr = strtok(NULL, " "); // Continue tokenizing
    }
    arguments[index] = NULL; // Terminate the array with NULL
    return arguments;
}

void getLocation()
{
    char location[BUFF_SIZE];

    if (getcwd(location, BUFF_SIZE) == NULL)
    {
        puts("Error");
    }
    else
    {
        blue();
        puts(location);
        reset();
    }

}
    void logout (char *input)
    {
        free(input);
        puts("Goodbye!");
        exit(EXIT_SUCCESS);
    }