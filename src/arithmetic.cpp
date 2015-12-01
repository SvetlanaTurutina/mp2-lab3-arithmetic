#include "arithmetic.h" 
#include <stdio.h>
#include <stdlib.h>

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

void PartitionIntoTokens(char *s)
{
	//
	int i, j = 0, k = 0, ind, iend;
	char operation[] = "-+*/";
	char operand[] = "abcdefghijklmnopqrstuvwxyz";
	char number[] = "0123456789";
	int len = strlen(s);
	char c[256];
	char lexem[32];

	i = 0;
	j = 0;
	ind = 0;
	while (i<len)
	{
		if ((s[i] == ' '))
		{
			iend = i;
			lexem[j] = '\0'; 
			if (strlen(lexem) > 0)
			{
				for (k = 0; k<strlen(lexem); k++)
				{
					c[ind] = lexem[k];
					ind++;
				}
				c[ind] = ' ';
				ind++;
			}
			i = iend + 1;
			lexem[0] = '\0';
			j = 0;
		}
		else if ((s[i] == '-') ||
			(s[i] == '+') ||
			(s[i] == '*') ||
			(s[i] == '/'))
		{
			iend = i;
			lexem[j] = '\0';
			for (k = 0; k < strlen(lexem); k++)
			{
				c[ind] = lexem[k];
				ind++;
			}
			c[ind] = ' ';
			ind++;
			c[ind] = s[i];
			ind++;
			c[ind] = ' ';
			ind++;
			i = iend + 1;
			lexem[0] = '\0';
			j = 0;
		}
		else
		{
			lexem[j] = s[i];
			i++;
			j++;
		}
	}
	lexem[j] = '\0';
	if (strlen(lexem) > 0)
	{
		for (k = 0; k < strlen(lexem); k++)
		{
			c[ind] = lexem[k];
			ind++;
		}
	}
	c[ind] = '\0';
	for (int i = 0; i < strlen(c); i++)
		cout << c[i];
}
int Priority(char ch)
{
	int res = -1;
	if (ch == '(')
		res = 0;
	if (ch == ')')
		res = 1;
	if ((ch == '-') || (ch == '+'))
		res = 2;
	if ((ch == '*') || (ch == '/'))
		res = 3;
	return res;
}
void ToPolish(char *s)
{
	int i, j = 0;
	TStack<char> op(30);
	char c[256]; // output string

	for (int i = 0; i < strlen(s); i++)
	{
		if ((s[i] == '+') || (s[i] == '-') || (s[i] == '*') || (s[i] == '/'))
		{
			if ((op.IsEmpty()) || (Priority(s[i]) > Priority(op.GetTopElem())))
				op.Put(s[i]);
			else while ((op.IsEmpty() != true) || (Priority(s[i]) <= Priority(op.GetTopElem())))
			{
				c[j] = op.GetTopElem();
				j++;
				op.GetDelTopElem(); // break
				if (op.IsEmpty())
				{
					op.Put(s[i]);
					break;
				}
					
			}
		}
		if (s[i] == '(') 
			op.Put(s[i]);
		if (s[i] == ')')
		{
			while (op.GetTopElem() != '(')
			{
				c[j] = op.GetTopElem();
				j++;
				op.GetDelTopElem();
			}
			//op.GetDelTopElem();
		}
		if ((s[i] != '+') && (s[i] != '-') && (s[i] != '*') && (s[i] != '/') && (s[i] != '(') && (s[i] != ')'))
		{
			c[j] = s[i];
			j++;
		}
		
		   
	}
	
	//if (i == strlen(s))
	    while (op.IsEmpty() != true)
	    {
		   c[j] = op.GetDelTopElem();
		   j++;
	    }
	c[j] = '\0';

	for (int j = 0; j < strlen(c); j++)
		cout << c[j];
}

void PolishFindResult(char *s)
{
	int i = 0;
	string lexem;
	TStack<double> op(30);
	double res, a, b, c;

	for (int i = 0; i < strlen(s); i++)
	{
		if ((s[i] == '+') || (s[i] == '-') || (s[i] == '*') || (s[i] == '/'))
		{
			if (s[i] == '+')
			{
				a = op.GetDelTopElem();
				b = op.GetDelTopElem();
				c = a + b;
				op.Put(c);
			}
			if (s[i] == '-')
			{
				a = op.GetDelTopElem();
				b = op.GetDelTopElem();
				c = b - a;
				op.Put(c);
			}
			if (s[i] == '*')
			{
				a = op.GetDelTopElem();
				b = op.GetDelTopElem();
				c = a * b;
				op.Put(c);
			}
			if (s[i] == '/')
			{
				a = op.GetDelTopElem();
				b = op.GetDelTopElem();
				c = b / a;
				op.Put(c);
			}
		}
		else if (s[i] != ' ')
		{
			if (isalpha(s[i]))
			{
				cout << "Enter value of variable\n";
				cin >> a;//scanf("%f", &a);
				op.Put(a);
			}
			else 
			{
				lexem = lexem + s[i];
				a = stod(lexem);
				op.Put(a);
				if (s[i + 1] == ' ')
				{
					lexem = ""; // clear string
					continue;
				}
			}
	
		}
	}
	res = op.GetDelTopElem();
	cout << res;
}