#include "C:\Users\DNS!\Downloads\studying\programming\3sem\mp2-lab3-arithmetic\include\arithmetic.h"

bool CheckBrackets(char* s)  // проверка скобок
{
	TStack<int> br(256);
	bool res = 1;
	int len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		if (s[i] == '(')
			br.Put(i);
		else if (s[i] == ')')
		{
			if (br.IsEmpty())
			{
				res = 0;
				cout << "Error. Irrelevant closing bracket in position " << i;
				break;
			}
			else
				br.GetDelTopElem();

		}
	}
	if (br.IsEmpty() != 1)
	{
		res = 0;
		cout << "Error. Irrelevant opening bracket in position " << br.GetTopElem();
	}

	return res;
}

bool CheckOperations(char* s)
{
	char operation[] = "-+*/";
	bool res = 1;
	int len = strlen(s);

	for (int i = 0; i < 3; i++)
	{
		if (s[0] == operation[i])
		{
			cout << "Error. Expression starts with operation sign";
			res = 0;
			break;
		}
		if (s[len - 1] == operation[i])
		{
			cout << "Error. Expression ends with operation sign";
			res = 0;
			break;
		}
	}
	
	return res;
}

bool CheckOperationsStandTogether(char* s)
{
	char operation[] = "-+*/";
	int len = strlen(s);
	bool res = 1;
	for (int i = 0; i < len-1; i++)
	{
		for (int j = 0; j < 3; j++)
		if (s[i] == operation[j])
		{
			for (int j = 0; j < 3; j++)
			if (s[i + 1] == operation[j])
			{
				cout << "Error. Operations stand one after another in positions " << i << " & " << i+1;
				res = 0;
				break;
			}
		}
	}
	return res;
}
bool CheckOperandsStandTogether(char* s)
{
	char operand[] = "abcdefghijklmnopqrstuvwxyz";
	int len = strlen(s);
	bool res = 1;
	for (int i = 0; i < len-1; i++) 
	{
		for (int j = 0; j < 25; j++)
		if (s[i] == operand[j])
		{
			for (int j = 0; j < 25; j++)
				if (s[i + 1] == operand[j])
				{
					cout << "Error. Operands stand one after another in positions " << i << " & " << i + 1;
					res = 0;
					break;
				}
		}
	}
	return res;
}
bool CheckOperandBracketStandTogether(char* s)
{
	char operand[] = "abcdefghijklmnopqrstuvwxyz";
	int len = strlen(s);
	bool res = 1;
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < 25; j++)
		if ((s[i] == operand[j])&&(s[i + 1] == '('))
			{
				cout << "Error. Operand stands before bracket in position " << i;
				res = 0;
				break;
			}
		for (int j = 0; j < 25; j++)
		if ((s[i] == ')') && (s[i + 1] == operand[j]))
		{
			cout << "Error. Operand stands after bracket in position " << i+1;
			res = 0;
			break;
		}
	}
	return res;
}