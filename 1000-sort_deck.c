#include "deck.h"
/**
 * valNum - func to associate value to number
 * @value: value to check
 * Return: int value
*/
int valNum(const char *value)
{
	const char *values[] = {
		"Ace", "2", "3", "4", "5", "6", "7", "8", "9",
		"10", "Jack", "Queen", "King"
		};
	const int numbers[] = {
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13
		};
	const size_t numValues = sizeof(values) / sizeof(values[0]);
	size_t i = 0;

	for (; i < numValues; i++)
	{
		if (!strcmp(value, values[i]))
			return (numbers[i]);
	}
	return (atoi(value));
}
/**
 * checkFunc - func to check cards.
 * @card1: first card.
 * @card2: second card.
 * Return: difference in value.
 */
int checkFunc(const card_t *card1, const card_t *card2)
{
	int c1 = valNum(card1->value);
	int c2 = valNum(card2->value);

	if (card1->kind == card2->kind)
		return (c1 - c2);
	return (card1->kind - card2->kind);
}
/**
 * dataSwitch - func to swap list nodes
 * @list: affected list
 * @node1: 1st node
 * @node2: 2nd node
 */
void dataSwitch(deck_node_t **list, deck_node_t *node1, deck_node_t *node2)
{
	node1->next = node2->next;
	if (node2->next)
		node2->next->prev = node1;
	node2->prev = node1->prev;
	if (node1->prev)
		node1->prev->next = node2;

	node1->prev = node2;
	node2->next = node1;
	if (!node2->prev)
		*list = node2;
}
/**
 * cocktail_sort_list - function to sort list using cocktail shaker sort algo
 * @list: list to be sorted
*/
void cocktail_sort_list(deck_node_t **list)
{
	deck_node_t *node, *nextNode, *prevNode;
	int sortFlag = 1;

	node = *list;
	while (sortFlag)
	{
		sortFlag = 0;
		for (; node->next;)
		{
			if (checkFunc(node->card, node->next->card) > 0)
			{
				sortFlag = 1;
				nextNode = node->next;
				dataSwitch(list, node, nextNode);
				node = nextNode;
			}
			node = node->next;
		}
		if (!sortFlag)
			break;
		for (; node->prev;)
		{
			if (checkFunc(node->card, node->prev->card) < 0)
			{
				sortFlag = 1;
				prevNode = node->prev;
				dataSwitch(list, prevNode, node);
				node = prevNode;
			}
			node = node->prev;
		}
	}
}
/**
 * sort_deck - sorting decj using cocktail sort algorithm
 * @deck: list
 */
void sort_deck(deck_node_t **deck)
{
	if (!deck || !(*deck) || !(*deck)->next)
		return;
	cocktail_sort_list(deck);
}
