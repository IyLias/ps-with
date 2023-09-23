#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <set>

#define MAXSIZE	27

bool alphabet_map[MAXSIZE][MAXSIZE];
// a b c d 

using namespace std;

void search() {

	for (int k = 0; k < MAXSIZE; k++)
		for (int i = 0; i < MAXSIZE; i++)
			for (int j = 0; j < MAXSIZE; j++)
			{
				if (alphabet_map[i][k] && alphabet_map[k][j])
					alphabet_map[i][j] = true;
			}
	
}


int main()
{
	int n;
	scanf("%d", &n);
	cin.ignore();

	for (int i = 0; i < n; i++) {
		string statement;
		getline(cin, statement);

		char p = statement[0], q = statement[5];
		int start = statement[0] - 'a';
		int end = statement[5] - 'a';
		alphabet_map[start][end] = true;
	}

	search();

	int m;
	scanf("%d", &m);
	cin.ignore();

	for (int i = 0; i < m; i++) {
		string statement;
		getline(cin, statement);

		char p = statement[0], q = statement[5];
		int start = statement[0] - 'a';
		int end = statement[5] - 'a';

		printf("%c\n", alphabet_map[start][end] ? 'T' : 'F');
	}

}

