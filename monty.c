#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

/* Define a stack and a variable to keep track of the top of the stack */
int stack[STACK_SIZE];
int top = -1; /* Initialize top to -1 to indicate an empty stack */

/* Function to push an integer onto the stack */
void push(int value)
{
    if (top >= STACK_SIZE - 1)
    {
        fprintf(stderr, "Error: Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack[++top] = value;
}

/* Function to print all values on the stack */
void pall()
{
    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char opcode[20]; /* Assuming opcode won't be longer than 20 characters */
    int arg;         /* Variable to store argument for push */

    while (fscanf(file, "%s", opcode) != EOF)
    {
        if (strcmp(opcode, "push") == 0)
        {
            if (fscanf(file, "%d", &arg) != 1)
            {
                fprintf(stderr, "Error: usage: push integer\n");
                exit(EXIT_FAILURE);
            }
            push(arg);
        }
        else if (strcmp(opcode, "pall") == 0)
        {
            pall();
        }
        else
        {
            fprintf(stderr, "Error: Invalid opcode: %s\n", opcode);
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
    return 0;
}
