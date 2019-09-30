#include "monty.h"
#include <ctype.h>

/**
 * rotl - rotates the stack to the top.
 * @stack:double pointer tot he begining of the linked list
 * @line_number: script line number
 *
 * Return: void
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack)
		*stack = (*stack)->next;
}

/**
 * rotr - rotates the stack to the bottom.
 * @stack: double pointer to the begining of the linked list
 * @line_number: script line number
 *
 * Return: void
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack)
		*stack = (*stack)->prev;
}

/**
 * m_stack - sets the format of the data to a stack (LIFO)
 * @stack: double pointer to the beginning of the stack
 * @line_number: script line number
 *
 * Return: void
 */
void m_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	var.queue = STACK;
}

#include "monty.h"

/**
 * m_queue - sets the format of the data to a queue (FIFO)
 * @stack: double pointer to the beginning of the stack
 * @line_number: script line number
 *
 * Return: void
 */
void m_queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	var.queue = QUEUE;
}

/**
 * m_pstr - print string from stack of ints up to null byte,
 * first non-ascii character, or end of stack
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 *
 * Return: void
 */
void m_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int ch;

	(void)line_number;

	temp = *stack;
	while (temp != NULL)
	{
		ch = temp->n;
		if (!isascii(ch) || ch == 0)
			break;
		putchar(ch);
		temp = temp->next;
		if (temp == *stack)
			break;
	}
	putchar('\n');
}
