#include "stack.h"

#define NULL 0

Stack::Stack()
{
    next = NULL;
}

void Stack::push(int x)
{
    Stack *tmp = this;
    while (tmp->next != NULL)
        tmp = tmp->next;
    Stack *cur = new Stack();
    cur->data = x;
    cur->next = NULL;
    tmp->next = cur;
}

int Stack::pop()
{
    Stack *last,
        *cur = this;
    while (cur->next != NULL)
    {
        last = cur;
        cur = cur->next;
    }
    last->next = NULL;
    return cur->data;
}

Stack::~Stack()
{
}
