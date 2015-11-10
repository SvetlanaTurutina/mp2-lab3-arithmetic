#include <iostream>

using namespace std;

const int MAX_STACK_SIZE = 100000000;

template <class ValType>
class TStack
{
protected:
	ValType *pMem;
	int Size;                                            // ������ �����
	int Top;                                             // ������ ���������� �������� � ���
	//int Mem[Size]; //

public:
	TStack(int s);
	TStack(const TStack &s);                             // ����������� �����������
	~TStack();
	int GetSize() const { return Size; } // 
	//int GetTopIndex() const { return Top; }              // �������� ������ ���������� �������� �������
	int GetNextIndex(int index) { return ++index; }
	int GetPrevIndex(int index) { if (index != 0) return index--; else throw "Stack is empty"; }
	bool IsEmpty() const;                            //�������� �� �������
	bool IsFull() const;                             //�������� �� ���������������
	void Put(const ValType n);                       //�������� � ����
	ValType GetTopElem();                            //����� �� ����� ��� ��������
	ValType GetDelTopElem();                            //����� �� ����� � ���������
	void Print();                                        //������ ��������

	bool operator==(const TStack &s) const;  // ���������
	bool operator!=(const TStack &s) const;  // ���������
	TStack& operator=(const TStack &s);     // ������������

	//TStack  operator+(const ValType &val);   // 
	//TStack  operator-(const ValType &val);   // 
};
	

template <class ValType>
TStack<ValType>::TStack(int s)
{
	if (s < 0 || s > MAX_STACK_SIZE)
		throw "Wrong stack size";

	pMem = new ValType[s];
	Size = s;
	Top = -1;

	for (int i = 0; i < Size; i++)
		pMem[i] = 0;

}
template <class ValType> 
TStack<ValType>::TStack(const TStack<ValType> &s) // ����������� �����������
{
	Size = s.GetSize();
	Top = s.Top;
	pMem = new ValType[Size];

	for (int i = 0; i < Size; i++)
		pMem[i] = s.pMem[i];
}
template <class ValType>
TStack<ValType>::~TStack()
{
	delete[] pMem;
}
template <class ValType>
bool TStack<ValType>::IsEmpty() const //�������� �� �������
{
	bool res = 0;
	if (Top == -1)
		res = 1;
	return res;
} 
template <class ValType>
bool TStack<ValType>::IsFull() const //�������� �� ���������������
{
	bool res = 0;
	if (Top == Size - 1)
		res = 1;
	return res;
}
template <class ValType>
void TStack<ValType>::Put(const ValType n) //�������� � ����
{
	if (pMem == NULL)
		throw "Memory is not allocated";
	else if (IsFull())
		throw "Stack overflow";
	else
	{
		//Top = GetNextIndex(Top);
		pMem[++Top] = n;
		//DataCount++;
	}
} 
template <class ValType>
ValType TStack<ValType>::GetTopElem() //����� �� ����� ��� ��������
{
	ValType temp = -1;
	if (pMem == NULL)
		throw "Memory is not allocated";
	else if (IsEmpty())
	throw "Stack is empty";
	else
	{
		temp = pMem[Top];
		//DataCount--;
	}
	return temp;
};
template <class ValType>
ValType TStack<ValType>::GetDelTopElem() //����� �� ����� � ���������
{
	ValType temp = -1;
	if (pMem == NULL)
		throw "Memory is not allocated";
	else if (IsEmpty())
	throw "Stack is empty";
	else
	{
		temp = pMem[Top--];
		//Top = GetPrevIndex(Top);
		//DataCount--;
	}
	return temp;
}
template <class ValType>
void TStack<ValType>::Print() //������ ��������
{
	for (int i = 0; i < Size; i++)
		printf("%d", pMem[i]);
	printf("\n");
}

template <class ValType> // ���������
bool TStack<ValType>::operator==(const TStack &s) const
{
	bool res = 1;
	if (Size != s.GetSize())
	{
		res = 0;
		//break;
	}
	else
	for (int i = 0; i < Size; i++)
	if (pMem[i] != s.pMem[i])
	{
		res = 0;
		break;
	};
	return res;
}

template <class ValType> // ���������
bool TStack<ValType>::operator!=(const TStack &s) const
{
	bool res = 0;
	if (Size != s.GetSize())
	{
		res = 1;
		//break;
	}
	else
	for (int i = 0; i < Size; i++)
	if (pMem[i] != s.pMem[i])
	{
		res = 1;
		break;
	};
	return res;
}
template <class ValType> // ������������
TStack<ValType>& TStack<ValType>::operator=(const TStack &s)
{
	if (this != &s)
	{
		if (Size != s.GetSize())
		{
			delete[] pMem;
			pMem = new ValType[s.GetSize()];
		}
		Size = s.GetSize();
		Top = s.Top;
		for (int i = 0; i < Size; i++)
			pMem[i] = s.pMem[i];
	}
	return *this;
}