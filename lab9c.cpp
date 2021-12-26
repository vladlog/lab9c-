#include <cstring>
#include <stdio.h>
#include <iostream>
#include <string>
#include <clocale>

using namespace std;
string word();
int size(string text);
string* word_count(string text, int& n, int& index);
string erased(string text, int& n);
string format(string text);
void print(string text);

int main()
{
	setlocale(LC_CTYPE, "rus");
	int index = 0, k;
	string text;
	string result;
	int n = size(text);


	text = word();
	result = erased(text, k);
	result = format(result);
	print(result);


	return 0;

}


string word()
{
	string text;
	text = "";
	cout << "Введите строчку: ";
	getline(cin, text);
	return text;
}

int size(string text)
{
	int n = count(text.begin(), text.end(), ' ') + 1;
	return n;
}

string* word_count(string text, int &n, int &index)
{	
    n = size(text);
	
	string* words = new string[n];
	string current_word = "";

	for (int i = 0; i <= text.size(); i++)
	{
		if (text[i] != ' ' && i< text.size())
			current_word += text[i];
		else
		{
			words[index] = current_word;
			current_word = "";
			index++;
		}

	}
	return words;
}

string erased(string text, int &n)
{
	int len=0, index = 0, flag = 0;
	string* words = word_count(text, n, index);
	string current = "";
	
	for (int i = 0; i < n; i++)
	{
		int count = 0;
		for (int j = 0; j < n; j++)
		{
			if (words[i] == words[j])
			{
				count++;
				flag = j;
			}
			if (count > 2 && j == n-1)
			{
				current = words[flag];
				len = current.size();
				text.erase(text.find(current), len);
			}
		}
	}
	
	
	return text;
}
string format(string text)
{
	size_t index;
	while ((index = text.find("  ")) != string::npos)
		text = text.replace(index, 2, " ");

	
	return text;
}
void print(string text)
{	
	cout << "Измененная строчка:" << text << endl;
}



