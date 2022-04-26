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

void push(Stack& s, int d)
{
	Element* e = (Element*)malloc(sizeof(Element));
	e->data = d;
	e->next = s.head;
	s.head = e;
}

int pull(Stack& s)
{
	if (s.head == NULL) return 0;
	int d = s.head->data;
	Element* e = s.head;
	s.head = s.head->next;
	free(e);
	return d;
}

void printStack(Stack& s)
{
	for (Element* cur = s.head; cur != NULL; cur = cur->next)
		printf("%d -> ", cur->data);
	printf("\b\b\b	\n");
}

int main()
{



	return 0;
}