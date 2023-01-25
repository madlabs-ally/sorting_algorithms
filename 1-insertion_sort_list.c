#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *	in ascending order using the Insertion sort algorithm
 *
 * @list: A pointer to the head of a doubly linked list
 *
 * Return: Nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *head, *current, *prev;
	bool swaped = false;

	if (*list && list && (*list)->next)
	{
		head = (*list)->next;
		while (head != NULL)
		{
			current = head;
			prev = current->prev;
			while (prev && current->n < prev->n)
			{
				swap_nodes(&prev, &current);
				swaped = true;
				if (prev == *list)
					*list = current;
				print_list(*list);
				prev = current->prev;
			}
			if (swaped == false)
				return;
			head = head->next;
		}
	}
}

/**
 * sorted_insert - Insert node in accending ordor
 *
 * @sorted: pointer to an empty list to insert to
 * @new: new node to insert to linked list
 *
 * Return: Nothing
 */

void sorted_insert(listint_t **sorted, listint_t *new)
{
	listint_t *current;

	if (*sorted == NULL)
		*sorted = new;
	else if ((*sorted)->n >= new->n)
	{
		new->next = *sorted;
		new->next->prev = new;
		*sorted = new;
	}
	else
	{
		current = *sorted;

		while (current->next != NULL && current->next->n < new->n)
			current = current->next;
		new->next = current->next;
		if (current->next != NULL)
			new->next->prev = new;

		current->next = new;
		new->prev = current;
	}
}

/**
* swap_nodes - Swap left and right nodes
*
* @A: pointer to left node
* @B: pointer to right node
*
* Return: Nothing
*/

void swap_nodes(listint_t **A, listint_t **B)
{
	(*A)->next = (*B)->next;
	(*B)->prev = (*A)->prev;

	if ((*B)->next != NULL)
		(*B)->next->prev = *A;

	if ((*A)->prev != NULL)
		(*A)->prev->next = *B;

	(*B)->next = *A;
	(*A)->prev = *B;
}
