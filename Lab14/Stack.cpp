#include"Stack.h"
#include<iostream>

void pushStack(Stack& s, int d)
{
	Element* tmp = (Element*)malloc(sizeof(Element));
	tmp->data = d;
	tmp->next = s.head;
	s.head = tmp;
}

int pullStack(Stack* s)
{
	if (s->head == NULL) return 0;
	int d = s->head->data;
	Element* tmp = s->head;
	s->head = s->head->next;
	free(tmp);
	return d;
}

void writeANumber(Stack* s)
{
	printf("Write a number:");
	for (char symbol = getchar(); symbol != '\n'; symbol = getchar())
		pushStack(*s, symbol - '0');
}

void printStack(Stack* s)
{
	printf("\nStack:\n");
	int i = 1;
	for (Element* cur = s->head; cur != NULL; cur = cur->next, i++)
		printf("%d -> %d\n", i, cur->data);
}

int reverseNumber(Stack* s)
{
	int len = 0, number = 0, st = 1;
	for (Element* cur = s->head; cur != NULL; cur = cur->next)
	{
		len++;
		st *= 10;
	}
	st /= 10;
	for (int i = 0; i < len; i++)
	{
		number += pullStack(s) * st;
		st /= 10;
	}
	return number;
}

void stackNumberMinAndMax(Stack* s)
{
	int min = 10, max = 0;
	for (Element* cur = s->head; cur != NULL; cur = cur->next)
	{
		if (cur->data > max)
			max = cur->data;
		if (cur->data < min)
			min = cur->data;
	}

	printf("\nMin - %d\nMax - %d\n", min, max);
}

void stackDestroy(Stack* s)
{
	while (s->head != NULL)
		pullStack(s);
}