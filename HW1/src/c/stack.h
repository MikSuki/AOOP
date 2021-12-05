#ifndef __STACK_H__
#define __STACK_H__

#define STACK_SIZE 100

struct stack
{
	int data;
	struct stack *next;
};

extern void push(struct stack *cur, int x);
extern int pop(struct stack *cur);
extern struct stack *new_stack();
extern void delete_stack(struct stack *stk);

#endif
