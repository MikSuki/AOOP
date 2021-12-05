#ifndef __STACK_H__
#define __STACK_H__

class Stack
{
    Stack *next;
    int data;

public:
    Stack();
    void push(int x);
    int pop();
    ~Stack();
};

#endif