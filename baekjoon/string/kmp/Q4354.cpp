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
	vector<int> table(p.length(), 0);

	int j = 0;
	for (int i = 1; i < p.length(); i++)
	{
		while ((j > 0) && (p[i] != p[j]))
			j = table[j - 1];

		if (p[i] == p[j]) {
			table[i] = j + 1;
			j++;
		}
	}

	return table;
}


void kmp(string s, string p, vector<int>& table) {

	int j = 0;
	for (int i = 0; i < s.length(); i++)
	{
		while ((j > 0) && (s[i] != p[j]))
			j = table[j - 1];

		if (s[i] == p[j])
			if (j == p.length() - 1)
			{
				search_idx.push_back(i - j + 1);
				j = table[j];
			}
			else
				j++;
	}

}

int main()
{

	while (true) {
		string S;
		getline(cin, S);

		if (S.compare(".") == 0) break;

		vector<int> table = create_table(S);

		int S_length = S.length();
		int a_length = S.length() - table[S.length() - 1];

		if (S_length % a_length == 0)
			printf("%d\n", S_length / a_length);
		else
			printf("1\n");

	}

	return 0;

}
