#include "lists.h"

listint_t reverse_list(listint_t *head)
{
	listint_t *prev = NULL;

	while(head != NULL)
	{
		listint_t *next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}

	return prev;
}

int is_palindrome(listint_t **head)
{
	if (head == NULL)
	{
		return 1;
	}

	listint_t *slow = head;
	listint_t *fast = head;

	while (fast->next != NULL && fast->next->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	
	listint_t *second_half = reverse_list(slow->next);
	listint_t *p1 = head;
	listint_t *p2 = second_half;

	while (p2 != NULL)
	{
		if (p1->n != p2->n)
		{
			return 0;
		}
		p1 = p1->next;
		p2 = p2->next;
	}

	slow->next = reverse_list(second_half);

	return 1;
}
