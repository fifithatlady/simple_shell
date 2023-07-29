#include "shell.h"

/**
 * list_len - it is a func to determines length of linked list
 * @h: this ia a pointer to first node in a row
 *
 * Return: this retuns a size of list at end
 */
size_t list_len(const list_t *h)
{
	size_t num = 0;

	while (h)
	{
		h = h->next;
		num++;
	}
	return (num);
}

/**
 * list_to_strings - tghe func brings back an array of strings of the list->str
 * @head: the pointer to first node
 *
 * Return: this retuns array of strings
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t num = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !num)
		return (NULL);
	strs = malloc(sizeof(char *) * (num + 1));
	if (!strs)
		return (NULL);
	for (num = 0; node; node = node->next, num++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < num; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[num] = str;
	}
	strs[num] = NULL;
	return (strs);
}


/**
 * print_list - ths the func that prints all elements of a list_t linked list
 * @h: the pointer to first node of a rw
 *
 * Return: always size of list
 */
size_t print_list(const list_t *h)
{
	size_t num = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		num++;
	}
	return (num);
}

/**
 * node_starts_with - it is a func returns node whose string starts with prefix
 * @node: this the pointer to list head of nodes
 * @prefix: the the resemplance string to match
 * @c: next character after prefix to match
 *
 * Return: always match node or null
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - this fetches the index of a node
 * @head: the pointer to list head
 * @node: the pointer to the node
 *
 * Return: always index of node or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t num = 0;

	while (head)
	{
		if (head == node)
			return (num);
		head = head->next;
		num++;
	}
	return (-1);
}
