#include "lists.h"

int is_palindrome(listint_t **head) {
    listint_t *slow, *fast, *reverseHead;
    int result;

    if (*head == NULL || (*head)->next == NULL) {
        return 1;
    }

    slow = *head;
    fast = (*head)->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    reverseHead = reverse(slow->next);
    slow->next = NULL;

    result = cmp(*head, reverseHead);

    reverse(reverseHead);
    slow->next = reverseHead;

    return result;
}


int cmp(listint_t *head1,listint_t *head2) 
{
	listint_t *list1 = head1;
	listint_t *list2 = head2;

	while (list1 != NULL && list2 != NULL)
	{
		if (list1->n != list2->n)
			return 0;

		list1 = list1->next;
		list2 = list2->next;
	}

	return 1;
}

listint_t *reverse(listint_t *head)
{
	listint_t *current = head;
	listint_t *prev = NULL;
	listint_t *next = NULL;


	while (current != NULL)
	{
		next = current->next;
		current->next = prev;

		prev = current;
		current = next;
	}

	return prev;
}
