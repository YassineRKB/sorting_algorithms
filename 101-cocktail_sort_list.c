#include "sort.h"
/**
 * cocktail_sort_list - function to sort list using cocktail shaker sort algo
 * @list: list to be sorted
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *node, *end;
	int sortFlag = 0;

	if (!list || !(*list) || !(*list)->next)
		return;

	while (!sortFlag)
	{
		sortFlag = 1;
		for (node = (*list)->next; node; node = node->next)
		{
			if (node->n < node->prev->n)
			{
				node_switcher(list, node->prev, node);
				print_list(*list);
				sortFlag = 0;
			}
			end = node;
		}

		if (sortFlag)
			break;

		for (node = end->prev; node; node = node->prev)
		{
			if (node->n > node->next->n)
			{
				node_switcher(list, node, node->next);
				print_list(*list);
				sortFlag = 0;
			}
		}
	}
}
/**
 * node_switcher -  function to switch nodes of double linked list
 * @list: affected list.
 * @nodeA: node 1 to be switched
 * @nodeB: node 2 to be switched
*/
void node_switcher(listint_t **list, listint_t *nodeA, listint_t *nodeB)
{
	if (nodeA->prev)
		nodeA->prev->next = nodeB;
	else
		*list = nodeB;
	if (nodeB->next)
		nodeB->next->prev = nodeA;
	nodeA->next = nodeB->next;
	nodeB->prev = nodeA->prev;
	nodeA->prev = nodeB;
	nodeB->next = nodeA;
}
