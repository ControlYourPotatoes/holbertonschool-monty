#include "monty.h"

/**
 * _swap - Swaps the top two elements of the stack.
 * @top: A pointer to the top of the stack.
 * @line_number: The line number in the Monty file.
 */
void _swap(stack_t **top, unsigned int line_number)
{
    int temp;

    if (!top || !*top || !(*top)->next)
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = (*top)->n;
    (*top)->n = (*top)->next->n;
    (*top)->next->n = temp;
}

/**
 * _add - Adds the top two elements of the stack.
 * @top: A pointer to the top of the stack.
 * @line_number: The line number in the Monty file.
 */
void _add(stack_t **top, unsigned int line_number)
{
    if (!top || !*top || !(*top)->next)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*top)->next->n += (*top)->n;
    pop_stack(top, line_number);
}

/**
 * _sub - Subtracts the top element from the second top element of the stack.
 * @top: A pointer to the top of the stack.
 * @line_number: The line number in the Monty file.
 */
void _sub(stack_t **top, unsigned int line_number)
{
    if (!top || !*top || !(*top)->next)
    {
        fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*top)->next->n -= (*top)->n;
    pop_stack(top, line_number);
}

/**
 * _div - Divides the second top element by the top element of the stack.
 * @top: A pointer to the top of the stack.
 * @line_number: The line number in the Monty file.
 */
void _div(stack_t **top, unsigned int line_number)
{
    if (!top || !*top || !(*top)->next )
    {
        div_error(line_number);
    }
    else if((*top)->n == 0)
    {
        div_error2(line_number);
    }


    (*top)->next->n /= (*top)->n;
    pop_stack(top, line_number);
}

/**
 * _mul - Multiplies the top two elements of the stack.
 * @top: A pointer to the top of the stack.
 * @line_number: The line number in the Monty file.
 */
void _mul(stack_t **top, unsigned int line_number)
{
    if (!top || !*top || !(*top)->next)
    {
        fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*top)->next->n *= (*top)->n;
    pop_stack(top, line_number);
}
