#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <string>

using namespace std;

vector<int> create_table(string p) {

	vector<int> table(p.length());
	table[0] = -1;
	
	int j = p.length();
	for (int i = 1; i < p.length(); i++)
	{
		j = table[i - 1];

		while ((p[i] != p[j + 1]) && (j >= 0))
			j = table[j];

		if (p[i] == p[j + 1])
			table[i] = j + 1;
		else
			table[i] = -1;

	}




	return table;
}


int kmp(string s, string p, vector<int> &table) {

	int j = 0;
	for (int i = 0; i < s.length(); i++)
	{
		while (s[i] != p[j] && j > 0)
			j = table[j - 1];
		
		if (s[i] == p[j])
			if (j == p.length() - 1)
				return 1;
			else
				j++;
	}

	return 0;
}





int main()
{
	string S, P;
	cin >> S >> P;

	vector<int> table = create_table(P);

	printf("%d\n", kmp(S, P, table));

	return 0;

}

