#include<iostream>
#include<Windows.h>
using namespace std;

int StringLength(const char str[]);
char* ToUpper(char str[]);
char* Shrink(char str[]);
bool isPalindrome(const char str[]);

void main()
{
	setlocale(LC_ALL, "");
	const int SIZE = 256;
	//char str[SIZE] = "Хорошо   живёт  на  свете   Винни  пух";
	char str[] = "Аргентина манит негра";
	cout << "Введите строку: ";
	SetConsoleCP(1251);
	cin.getline(str, SIZE);
	SetConsoleCP(866);
	cout << str << endl;
	cout << StringLength(str) << endl;
	cout << strlen(str) << endl; //return size from str in symbol
	//cout << ToUpper(str) << endl;
	cout << Shrink(str) << endl;
	cout << "Строка " << (isPalindrome(str) ? "" : "НЕ ") << "является палиндромом" << endl;
}

int StringLength(const char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}

char* ToUpper(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		//if (str[i] >= 'a' && str[i] <= 'z')str[i] -= ' ';
		//if (str[i] >= 'а' && str[i] <= 'я')str[i] -= ' ';
		//if (str[i] == 'ё')str[i] -= 16;
		str[i] = toupper(str[i]);
	}
	return str;
}
char* Shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
		{
			for (int j = i + 1; str[j]; j++)str[j] = str[j + 1];
		}
	}
	return str;
}
char* RemoveSymbol(char str[], const char symbol)
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == symbol)
		{
			for (int j = i; str[j]; j++)str[j] = str[j + 1];
		}
	}
	return str;
}
bool isPalindrome(const char str[])
{
	int n = strlen(str);
	char* buffer = new char[n+1] {};
	for (int i = 0; str[i]; i++)
	{
		buffer[i] = str[i];
	}
	ToUpper(buffer);
	n = strlen(RemoveSymbol(buffer, ' '));
	for (int i = 0; i < n/2; i++)
	{
		if (buffer[i] != buffer[n - 1 - i])
		{
			delete[]buffer;
			return false;
		}
	}
	delete[]buffer;
	return true;
}