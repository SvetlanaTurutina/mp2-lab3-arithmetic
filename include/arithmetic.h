#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "stack.h"

using namespace std;

bool CheckBrackets(char* s);  // проверка скобок
bool CheckOperations(char* s); 
bool CheckOperandsStandTogether(char* s);  // проверка операндов
bool CheckOperationsStandTogether(char* s); // проверка операций
bool CheckOperandBracketStandTogether(char* s);
void PartitionIntoTokens(char *s);
int Priority(char ch);
void ToPolish(char *s);
void PolishFindResult(char *s);