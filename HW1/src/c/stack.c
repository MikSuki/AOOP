#include <stdlib.h>
#include "stack.h"

void push(struct stack *top, int x)
{
    struct stack *tmp = top;
    while (tmp->next != NULL)
        tmp = tmp->next;
    struct stack *cur = (struct stack *)malloc(sizeof(struct stack));
    cur->data = x;
    cur->next = NULL;
    tmp->next = cur;
}

int pop(struct stack *top)
{
    struct stack *last = NULL,
                 *cur = top;
    while (cur->next != NULL)
    {
        last = cur;
        cur = cur->next;
    }
    last->next = NULL;
    return cur->data;
}

struct stack *new_stack()
{
    struct stack *stk = (struct stack *)malloc(sizeof(struct stack));
    stk->next = NULL;
    return stk;
}

void delete_stack(struct stack *stk)
{
    free(stk);
}
