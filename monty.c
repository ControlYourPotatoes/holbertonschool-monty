#include "monty.h"
int number = -1;
/**
 * open_and_read -main entry.
 *Description:Function that open, read and execute.
 * @argv: arguments received by parameter
 * Return: void
 **/
void monty_prog(char **argv)
{
    /* prototype from struct instructions*/
    void (*p_func)(stack_t **, unsigned int);
    FILE *fp;
    char *buf = NULL, *token = NULL, command[1024];
    size_t len = 0;
    ssize_t line_size;
    unsigned int line_counter = 1;
    stack_t *top = NULL;

    fp = fopen(argv[1], "r");
    if (fp == NULL)
        open_error(argv);
    while ((line_size = getline(&buf, &len, fp)) != EOF)
    {
        token = strtok(buf, "\n\t\r ");
        if (token == NULL)
            continue;
        strcpy(command, token);
        if (is_comment(token, line_counter) == 1)
            continue;

        if (strcmp(token, "push") == 0)
        {
            token = strtok(NULL, "\n\t\r ");
            printf("%s\n", token);
            if (token == NULL)
                not_int_err(line_counter);
            number = atoi(token); /* update global variable */
            /*p_func will receive the function to execute*/
            p_func = get_op_code(command, line_counter);
            /* p_func takes the place of the function to execute: push, pall, etc*/
            p_func(&top, line_counter);
        }
        else
        {
            p_func = get_op_code(token, line_counter);
            p_func(&top, line_counter);
        }
        line_counter++;
    }
    fclose(fp);
    if (buf != NULL)
        free(buf);
    free_stack(top);
}


/**
 * is_number - check if string received is int or not
 * @token: string to check
 * Return: -1 if sring is not int or 1 if yes
 */
int is_number(char *token)
{
    int i;

    if (token == NULL)
        return (-1);

    for (i = 0; token[i] != '\0'; i++)
    {
        if (token[i] != '-' && isdigit(token[i]) == 0)
            return (-1);
    }
    return (1);
}
/**
 * is_comment - check if string received is # or not
 * @token: string to check
 * @line_counter: line
 * Return: -1 if sring is not # or 1 if yes
 */
int is_comment(char *token, int line_counter)
{
    if (token == NULL || token[0] == '#')
    {
        line_counter++;
        return (1);
    }
    return (-1);
}

/**
 * tokenization - extract tokens from the getline command
 *
 * @ptr: String of the command line
 * @delim: Delimiter
 * Return: the array of tokens
 * Description: We first allocate space for the array of tokens.
 */
char **tokenization(char *ptr, char *delim)
{
    char *token = NULL, **tokens = NULL;
    int i = 0;

    tokens = malloc(sizeof(char *) * 10);
    token = strtok(ptr, delim);

    while (token)
    {
        tokens[i] = malloc(sizeof(char) * strlen(token) + 1);
        strcpy(tokens[i], token);
        i++;
        token = NULL;
        token = strtok(NULL, delim);
    }

    tokens[i] = NULL;
    free(token);
    return (tokens);
}