#include<iostream>

/*Задание:
Ввести некоторое число и записать его цифры в стек.Вывести число, у которого цифры идут в обратном порядке.
Цифры из записи числа считывать поочередно(например, с помощью getch()).
Вычислить наименьшую и наибольшую цифры в записи числа.*/

struct Element
{
	int data;
	Element* next = NULL;
};

struct Stack
{
	Element* head = NULL;
};

void stackPush(Stack& s, int d)
{
	Element* e = (Element*)malloc(sizeof(Element));
	e->data = d;
	e->next = s.head;
	s.head = e;
}

int stackPull(Stack& s)
{
	if (s.head == NULL) return 0;
	int d = s.head->data;
	Element* e = s.head;
	s.head = s.head->next;
	free(e);
	return d;
}

void writeANumber(Stack* s)
{
	printf("Write a number:");
	for (char symbol = getchar(); symbol != '\n'; symbol = getchar())
		stackPush(*s, symbol - 48);
}

void printStack(Stack& s)
{
	printf("\nStack:\n");
	int i = 1;
	for (Element* cur = s.head; cur != NULL; cur = cur->next, i++)
		printf("%d -> %d\n", i, cur->data);

	/*printf("\nReverse - ");	
	for (int i = s->head; i >= 0; i--)
		printf("%d", s->element[i]);
	printf("\n");*/
}

/*void stackNumberMinAndMax(Stack* s)
{
	int min = 10, max = 0;
	for (int i = s->head; i >= 0; i--)
	{
		if (s->element[i] > max)
			max = s->element[i];
		if (s->element[i] < min)
			min = s->element[i];
	}

	printf("Min - %d\nMax - %d\n", min, max);
}*/

void stackDestroy(Stack* s)
{
	while (s->head != NULL)
		stackPull(*s);
}

int main()
{
	Stack s;
	writeANumber(&s);

	printStack(s);

	stackDestroy(&s);

	return 0;
}