#include "monty.h"
int number;
/**
 * push_stack - Pushes an element onto the stack.
 * @top: A pointer to the top of the stack.
 * @line_number: The line number in the Monty file.
 */
void push_stack(stack_t **top, unsigned int line_number)
{
	stack_t *newNode;

	(void) line_number;
	newNode = malloc(sizeof(stack_t));

	if (newNode == NULL)
		malloc_error();

	newNode->n = number;
	newNode->prev = NULL;
	if (*top == NULL)  /* validate if empty stack */
	{
		newNode->next = NULL;
		*top = newNode;
	}
	else /* if is not empty stack */
	{
	newNode->next = *top;
	(*top)->prev = newNode;
	*top = newNode;
	}
}

/**
 * pall_stack -print.
 *Description: Function that print the elements of a stack
 * @top: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: void
 **/
void pall_stack(stack_t **top, unsigned int line_number)
{
    stack_t *tmp = *top;
    (void)line_number;

    while (tmp != NULL)
    {
        printf("%d\n", tmp->n);
        tmp = tmp->next;
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


