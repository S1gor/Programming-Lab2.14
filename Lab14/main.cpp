#include"Stack.h"

/*�������:
������ ��������� ����� � �������� ��� ����� � ����.������� �����, � �������� ����� ���� � �������� �������.
����� �� ������ ����� ��������� ����������(��������, � ������� getch()).
��������� ���������� � ���������� ����� � ������ �����.*/

int main()
{
	Stack s;
	writeANumber(&s);

	printStack(&s);
	stackNumberMinAndMax(&s);
	int reverse = reverseNumber(&s);
	printf("\nReverse:\n%d\n", reverse);

	stackDestroy(&s);

	return 0;
}