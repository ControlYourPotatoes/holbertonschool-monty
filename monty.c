#include "monty.h"

int n = 0;

/**
 * monty_prog - Monty bytecode interpreter program
 * @argv: Command-line arguments, including the Monty bytecode file name.
 */
void monty_prog(char **argv)
{
    char *file_name = argv[1];
    char *buf = NULL;
    size_t len = 0;
    ssize_t line_size;
    unsigned int line_number = 0;
    stack_t *stack = NULL;

    FILE *fp = fopen(file_name, "r");
    if (!fp)
    {
        fprintf(stderr, "Error: Can't open file %s\n", file_name);
        exit(EXIT_FAILURE);
    }

    while ((line_size = getline(&buf, &len, fp)) != -1)
    {
        line_number++;
        char *token;
        char *saveptr;

        /* Tokenize the input line */
        token = strtok_r(buf, " \t\n", &saveptr);

        if (token)
        {
            void (*op_func)(stack_t **, unsigned int);

            /* Get the function pointer for the opcode */
            op_func = get_op_code(token, line_number);

            /* Call the appropriate function with the remaining arguments */
            if (op_func)
            {
                token = strtok_r(NULL, " \t\n", &saveptr);
                n = token ? atoi(token) : 0; /* Set global variable n */
                op_func(&stack, line_number);
            }
        }
    }

    free(buf);
    fclose(fp);
    free_stack(stack);
}
