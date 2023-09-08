#include "monty.h"

/**
 * get_op_code - Get the function pointer for the given opcode.
 * @token: The opcode token to look up.
 * @line: The line number in the Monty file.
 *
 * Return: A pointer to the function corresponding to the opcode.
 */
void (*get_op_code(char *token, unsigned int line))(stack_t **, unsigned int)
{
    int i;
    instruction_t operation[] = {
        {"push", push_stack},
        {"pall", pall_stack},
        {"pint", pint_stack},
        {"pop", pop_stack},
        {"swap", _swap},
        {"nop", _nop},
        {"add", _add},
        {"sub", _sub},
        {"div", _div},
        {"mul", _mul},
        {"mod", _mod},
        {"rotl", rotl_stack},
        {"rotr", rotr_stack},
        {"pchar", _pchar},
        {NULL, NULL}};
    for (i = 0; operation[i].opcode != NULL; i++)
    {
        if (strcmp(token, operation[i].opcode) == 0)
        {
            return (operation[i].f);
        }
    }
    /* if not found*/
    fprintf(stderr, "L%u: unknown instruction %s\n", line, token);
    exit(EXIT_FAILURE);
}
