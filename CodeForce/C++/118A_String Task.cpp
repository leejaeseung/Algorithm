/*
. String Task
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Petya started to attend programming lessons. On the first lesson his task was to write a simple program. The program was supposed to do the following: in the given string, consisting if uppercase and lowercase Latin letters, it:

deletes all the vowels,
inserts a character "." before each consonant,
replaces all uppercase consonants with corresponding lowercase ones.
Vowels are letters "A", "O", "Y", "E", "U", "I", and the rest are consonants. The program's input is exactly one string, it should return the output as a single string, resulting after the program's processing the initial string.

Help Petya cope with this easy task.

Input
The first line represents input string of Petya's program. This string only consists of uppercase and lowercase Latin letters and its length is from 1 to 100, inclusive.

Output
Print the resulting string. It is guaranteed that this string is not empty.

풀이:
문자열을 훑으면서 모음이면 벡터에 넣지 않고, 자음이면 앞에 . 을 붙이고 소문자로 바꿔서 벡터에 넣는다.
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pii pair<int, int>;

vector<char> vt;

int main(void) {
	FIO;

	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		char now = str.at(i);

		if (now >= 'A' && now <= 'Z') {
			if (now == 'A' || now == 'O' || now == 'E' || now == 'U' || now == 'I' || now == 'Y') continue;
			
			vt.push_back('.');
			vt.push_back(now - 'A' + 'a');
		}
		else {
			if (now == 'a' || now == 'o' || now == 'e' || now == 'u' || now == 'i' || now == 'y') continue;

			vt.push_back('.');
			vt.push_back(now);
		}
	}
	for (int i = 0; i < vt.size(); i++)
	{
		cout << vt.at(i);
	}
}