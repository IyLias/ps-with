#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <string>

using namespace std;

vector<int> search_idx;

vector<int> create_table(string p) {
	// table은 i번째 인덱스까지에서 접두와 접미가 일치하는 최대 길이 값을 저장
	vector<int> table(p.length(),0);
	
	int j = 0;
	for (int i = 1; i < p.length(); i++)
	{
		while ((j > 0) && (p[i] != p[j]))
			j = table[j-1];

		if (p[i] == p[j]) {
			table[i] = j + 1;
			j++;
		}
	}

	return table;
}


int kmp(string s, string p, vector<int> &table) {

	int j = 0;
	for (int i = 0; i < s.length(); i++)
	{
		while ((j > 0) && (s[i] != p[j]))
			j = table[j - 1];
		
		if (s[i] == p[j])
			if (j == p.length() - 1)
			{
				return 1;
			}
			else
				j++;
	}

	return 0;
}





int main()
{
	string S, P;
	getline(cin, S);
	getline(cin, P);

	vector<int> table = create_table(P);

	kmp(S, P, table);


	return 0;

}

