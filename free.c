#include "monty.h"

/**
 * free_stack - frees the stack on exit
 * @status: exit status
 * @arg: double pointer to the stack
 *
 * Return: void
 */
void free_stack(int status, void *arg)
{
	stack_t **stack;
	stack_t *next;

	(void)status;

	stack = (stack_t **)arg;
	if (*stack)
	{
		(*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
	}
	while (*stack != NULL)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = next;
	}
	var.stack_len = 0;
}

#include "monty.h"

/**
 * free_lineptr - free line pointer returned by getline
 * @status: exit status
 * @arg: pointer to line
 *
 * Return: void
 */
void free_lineptr(int status, void *arg)
{
	char **lineptr = arg;

	(void)status;
	if (*lineptr != NULL)
		free(*lineptr);
}
#include "monty.h"

/**
 * m_fs_close - close file stream
 * @status: status passed to exit
 * @arg: pointer to file stream
 *
 * Return: void
 */
void m_fs_close(int status, void *arg)
{
	FILE *fs;

	(void)status;

	fs = (FILE *) arg;
	fclose(fs);
}
