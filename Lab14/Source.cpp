#include<iostream>

/*�������:
������ ��������� ����� � �������� ��� ����� � ����.������� �����, � �������� ����� ���� � �������� �������.
����� �� ������ ����� ��������� ����������(��������, � ������� getch()).
��������� ���������� � ���������� ����� � ������ �����.*/

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
	int d = s.head->data;
	Element* e = s.head;
	s.head = s.head->next;
	free(e);
	return d;
}

void printStack(Stack& s)
{

}

int main()
{



	return 0;
}