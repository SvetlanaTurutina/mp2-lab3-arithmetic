#include "arithmetic.h"
void main()
{
	char s[256];// = "";
	char c[256];
	bool end = 0;
	int r, len;

	cout << "\nEnter an expression\n";
	cin >> s;
	len = strlen(s);
	s[len] = '\0';
	do
	{
		
		cout << "Press\n";
		cout << "1. If you want to check is expression correct or not\n";
		cout << "2. If you want to convert expression to polish notation\n";
		cout << "3. If you want to calculate the value of expression\n";
		cin >> r;
		
		switch (r)
		{
		case 1:
		{
				  CheckBrackets(s);  
				  CheckOperations(s);
				  CheckOperandsStandTogether(s);  
				  CheckOperationsStandTogether(s); 
				  CheckOperandBracketStandTogether(s);
				  break;
		}
		case 2:
		{
				  PartitionIntoTokens(s);
				  cout << "\n";
				  ToPolish(s, c);
				  break;
		}
		case 3:
		{
				  PartitionIntoTokens(s);
				  cout << "\n";
				  ToPolish(s, c);
				  cout << "\n";
				  double result = PolishFindResult(c);
				  cout << result;
				  break;
		}

			
		}

		cout << "\n\nWhat would you like to do next?\n";
		cout << "Press\n";
		cout << "1. Calculate another expression\n";
		cout << "2. Continue with current expression\n";
		cout << "3. Exit\n";
		cin >> r;

		switch (r)
		{
		case 1:
		{
				  cout << "\nEnter an expression\n";
				  cin >> s;
				  break;
		}
		case 2: continue;
		case 3: end = 1; break;
		}

	
	} 
	while (end != 1);
	cout << "\nEnd\n";
 
}