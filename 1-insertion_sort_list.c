#include "sort.h"
/**
 * insertion_sort_list - func to sort list using insert algo
 * @list: list to be sorted
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *aux, *node;

	if (!list || !(*list) || !(*list)->next)
		return;
	for (node = *list; node; node = node->next)
	{
		for (; node->next && (node->n > node->next->n);)
		{
			aux = node->next;
			node->next = aux->next;
			aux->prev = node->prev;
			if (node->prev)
				node->prev->next = aux;
			if (node->next)
				node->next->prev = node;
			node->prev = aux;
			aux->next = node;
			if (!aux->prev)
				*list = aux;
			else
				node = aux->prev;
			print_list(*list);
		}
	}
}
