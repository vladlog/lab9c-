#include <cstring>
#include <stdio.h>
#include <iostream>
#include <string>
#include <clocale>

using namespace std;
string text();
int size(string line);
string* counter(string line, int& n, int& index);
string del(string line, int& n);
string format(string line);
void print(string line);

int main(){
	setlocale(LC_CTYPE, "rus");
	int m;
	string line;
	string result;
	int n = size(line);
	line = text();
	result = del(line, m);
	result = format(result);
	print(result);
	return 0;
}

string text(){
	string line;
	line = "";
	cout << "Введите строчку: ";
	getline(cin, line);
	return line;
}

int size(string line){
	int n = count(line.begin(), line.end(), ' ') + 1;
	return n;
}

string* counter (string line, int& n, int& index){
	n = size(line);
	string* words = new string[n];
	string c_word = "";
	for (int i = 0; i <= line.size(); i++){
		if (line[i] != ' ' && i < line.size())
			c_word += line[i];
		else{
			words[index] = c_word;
			c_word = "";
			index++;
		}
	}
	return words;
}

string del(string line, int& n){
	int t = 0, bool_F = 0, index = 0;
	string* words = counter(line, n, index);
	string current = "";
	for (int i = 0; i < n; i++){
		int count = 0;
		for (int j = 0; j < n; j++)
		{
			if (words[i] == words[j]){
				count++;
				bool_F = j;
			}
			if (count > 2 && j == n - 1){
				current = words[bool_F];
				t = current.size();
				line.erase(line.find(current), t);
			}
		}
	}
	return line;
}
string format(string line){
	size_t index;
	while ((index = line.find("  ")) != string::npos)
		line = line.replace(index, 2, " ");
	return line;
}
void print(string line){
	cout << "Измененная строчка:" << line << endl;
}
