#ifndef _STACK_H_
#define _STACK_H_

#include<iostream>

struct Element
{
	int data;
	Element* next = NULL;
};

struct Stack
{
	Element* head = NULL;
};

void pushStack(Stack& s, int d);

int pullStack(Stack* s);

void writeANumber(Stack* s);

void printStack(Stack* s);

int reverseNumber(Stack* s);

void stackNumberMinAndMax(Stack* s);

void stackDestroy(Stack* s);

#endif