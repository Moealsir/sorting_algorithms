#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending order
 *                       using the Cocktail Shaker Sort algorithm.
 * @list: A pointer to the doubly linked list
 */
void cocktail_sort_list(listint_t **list) {
    int swapped;
    listint_t *current;

    if (list == NULL || *list == NULL)
        return;

    do {
        swapped = 0;
        /* Traverse forward */
        for (current = *list; current->next != NULL; current = current->next) {
            if (current->n > current->next->n) {
                /* Swap nodes */
                if (current->prev != NULL)
                    current->prev->next = current->next;
                else
                    *list = current->next;
                current->next->prev = current->prev;
                current->prev = current->next;
                current->next = current->next->next;
                current->prev->next = current;
                if (current->next != NULL)
                    current->next->prev = current;
                print_list(*list);
                swapped = 1;
            }
        }

        if (swapped == 0)
            break;

        swapped = 0;
        /* Traverse backward */
        for (; current->prev != NULL; current = current->prev) {
            if (current->n < current->prev->n) {
                /* Swap nodes */
                if (current->next != NULL)
                    current->next->prev = current->prev;
                current->prev->next = current->next;
                current->next = current->prev;
                current->prev = current->prev->prev;
                current->next->prev = current;
                if (current->prev != NULL)
                    current->prev->next = current;
                else
                    *list = current;
                print_list(*list);
                swapped = 1;
            }
        }
    } while (swapped);
}

