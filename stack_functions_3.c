#include "monty.h"
#include <ctype.h>

/**
 * m_pchar - print character from top of stack
 * @stack: double pointer to top of stack
 * @line_number: line number of current operation
 *
 * Return: void
 */
void m_pchar(stack_t **stack, unsigned int line_number)
{
	int ch;

	if (var.stack_len < 1)
	{
		fprintf(stderr,
			"L%u: can't pchar, stack empty\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	ch = (*stack)->n;
	if (!isascii(ch))
	{
		fprintf(stderr,
			"L%u: can't pchar, value out of range\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", ch);
}

/**
 * m_mul - multiply top two elements of stack and push result
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 *
 * Return: void
 */
void m_mul(stack_t **stack, unsigned int line_number)
{
	int n;

	if (var.stack_len < 2)
	{
		fprintf(stderr,
			"L%u: can't mul, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	m_pop(stack, line_number);
	(*stack)->n *= n;
}

/**
 * m_div - divide second element of stack by top element
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 *
 * Return: void
 */
void m_div(stack_t **stack, unsigned int line_number)
{
	int n;

	if (var.stack_len < 2)
	{
		fprintf(stderr,
			"L%u: can't div, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	m_pop(stack, line_number);
	if (n == 0)
	{
		fprintf(stderr,
			"L%u: division by zero\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->n /= n;
}

/**
 * m_mod - compute remainder (modulus) of second element divided by top element
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 *
 * Return: void
 */
void m_mod(stack_t **stack, unsigned int line_number)
{
	int n;

	if (var.stack_len < 2)
	{
		fprintf(stderr,
			"L%u: can't mod, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	m_pop(stack, line_number);
	if (n == 0)
	{
		fprintf(stderr,
			"L%u: division by zero\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->n %= n;
}
