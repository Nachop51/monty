#include "monty.h"
/**
 * rotl - Rotates the stack to the top.
 * @head: Linked list.
 * @lineCount: Number of the line.
 */
void rotl(stack_t **head, unsigned int lineCount)
{
	stack_t *list = *head, *newlist;
	int aux_n;

	if (*head == NULL || list->next == NULL)
		return;
	while (list->next != NULL)
		list = list->next;
	aux_n = list->n;
	newlist = add_node_start(head);
	newlist->n = aux_n;
	pop(head, lineCount);
}
