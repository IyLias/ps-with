#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <set>

#define INF	98765432
#define MAXSIZE	54

int alphabet_map[MAXSIZE][MAXSIZE];
// A B C D ... a b c d 

using namespace std;

int search() {

	for(int k=0;k<MAXSIZE;k++)
		for(int i=0;i<MAXSIZE;i++)
			for (int j = 0; j < MAXSIZE; j++)
			{
				if (alphabet_map[i][k] != INF && alphabet_map[k][j] != INF)
					alphabet_map[i][j] = min(alphabet_map[i][j], alphabet_map[i][k] + alphabet_map[k][j]);
			}

	int result = 0;
	for (int i = 0; i < MAXSIZE; i++)
		for (int j = 0; j < MAXSIZE; j++)
			if (i != j && alphabet_map[i][j] != 0 && alphabet_map[i][j] != INF)
				result++;

	return result;
}


int main()
{
	int X;
	scanf("%d", &X);
	cin.ignore();

	for (int i = 0; i < MAXSIZE; i++)
		for (int j = 0; j < MAXSIZE; j++)
			alphabet_map[i][j] = INF;

	for (int i = 0; i < X; i++) {
		string statement;
		getline(cin,statement);

		char p = statement[0], q = statement[5];
		int start = statement[0] >= 'a' ? statement[0] - 'a' + 26 : statement[0] - 'A';
		int end = statement[5] >= 'a' ? statement[5] - 'a' + 26 : statement[5] - 'A';
		alphabet_map[start][end] = 1;

	}

	int result = search();

	printf("%d\n", result);
	for(int i=0;i<MAXSIZE;i++)
		for(int j=0;j<MAXSIZE;j++)
			if (i != j && alphabet_map[i][j]!=0 && alphabet_map[i][j] != INF) {
				char p = i >= 26 ? i - 26 + 'a' : i + 'A';
				char q = j >= 26 ? j - 26 + 'a' : j + 'A';
				printf("%c => %c\n", p, q);
			}

}

