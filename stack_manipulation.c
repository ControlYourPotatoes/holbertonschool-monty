#include "monty.h"

/**
 * push_stack - Pushes an element onto the stack.
 * @top: A pointer to the top of the stack.
 * @line_number: The line number in the Monty file.
 */
void push_stack(stack_t **top, unsigned int line_number)
{
    stack_t *new_node;
    char *value;

    if (!top)
    {
        fprintf(stderr, "Error: top is NULL\n");
        exit(EXIT_FAILURE);
    }

    if (n == 0)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    value = strtok(NULL, " \n");
    if (!value)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = atoi(value);
    new_node->prev = NULL;
    new_node->next = *top;

    if (*top)
        (*top)->prev = new_node;
    *top = new_node;
}

/**
 * pall_stack - Prints all values on the stack.
 * @top: A pointer to the top of the stack.
 * @line_number: The line number in the Monty file.
 */
void pall_stack(stack_t **top, unsigned int line_number)
{
    stack_t *current = *top;

    (void)line_number;

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

/**
 * free_stack - Frees the memory allocated for the stack.
 * @top: A pointer to the top of the stack.
 */
void free_stack(stack_t *top)
{
    stack_t *current = top;

    while (current)
    {
        stack_t *next = current->next;
        free(current);
        current = next;
    }
}

/**
 * pint_stack - Prints the value at the top of the stack.
 * @top: A pointer to the top of the stack.
 * @line_number: The line number in the Monty file.
 */
void pint_stack(stack_t **top, unsigned int line_number)
{
    if (!top || !*top)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*top)->n);
}

/**
 * pop_stack - Removes the top element from the stack.
 * @top: A pointer to the top of the stack.
 * @line_number: The line number in the Monty file.
 */
void pop_stack(stack_t **top, unsigned int line_number)
{
    stack_t *temp;

    if (!top || !*top)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *top;
    *top = (*top)->next;
    if (*top)
        (*top)->prev = NULL;

    free(temp);
}
