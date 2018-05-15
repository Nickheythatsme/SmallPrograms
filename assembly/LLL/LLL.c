#include "LLL.h"

int insert(struct node **head, int new_data)
{
    if (!*head)
    {
        *head = (struct node*) malloc(sizeof(struct node));
        (*head)->data = new_data;
        return 0; 
    }
    return _insert(*head, new_data) + 1;
}

int _insert(struct node *head, int new_data)
{
    if (!head->next)
    {
        head->next = (struct node*) malloc(sizeof(struct node));
        head->next->data = new_data;
        return 1;
    }
    return _insert(head->next, new_data) + 1;
}

int remove_LLL(struct node **head, int to_remove)
{
    if (!*head) return -1;
    if ((*head)->data == to_remove)
    {
        struct node *new_head = *head;
        (*head) = (*head)->next;
        free(new_head);
        return 1;
    }
    return _remove_LLL(*head, to_remove);
}

int _remove_LLL(struct node *head, int to_remove)
{
    if (!head->next) return 0;
    if (head->next->data == to_remove)
    {
        struct node *temp = head->next->next;
        free(head->next);
        head->next=temp;
        return 1;
    }
    return _remove_LLL(head->next, to_remove);
}
