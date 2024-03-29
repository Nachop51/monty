#include "monty.h"
/**
 * sub - Subtracts the top element of the stack from the second.
 * @head: Linked list.
 * @lineCount: Line counter.
 */
void sub(stack_t **head, unsigned int lineCount)
{
	stack_t *list = *head;
	int result = 0;

	if (*head == NULL || list->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", lineCount);
		exit(EXIT_FAILURE);
	}
	while (list->next->next != NULL)
		list = list->next;
	result = list->n - list->next->n;
	list->n = result;
	pop(head, lineCount);
}
