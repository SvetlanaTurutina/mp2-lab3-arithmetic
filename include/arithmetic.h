#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "stack.h"

using namespace std;

bool CheckBrackets(char* s);  // �������� ������
bool CheckOperations(char* s); 
bool CheckOperandsStandTogether(char* s);  // �������� ���������
bool CheckOperationsStandTogether(char* s); // �������� ��������
bool CheckOperandBracketStandTogether(char* s);