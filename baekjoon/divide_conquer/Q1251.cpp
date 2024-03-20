#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <set>


using namespace std;

string best_result="";

string combination(string process, string remained, int count) {

	if (count == 3) {
		string result = process;
		reverse(remained.begin(), remained.end());
		result += remained;
		return result;
	}

	for (int i = 0; i < remained.length()-1; i++)
	{
		string substring = remained.substr(0, i + 1);
		reverse(substring.begin(), substring.end());
		
		string rest = remained.substr(i+1,remained.length()-(i+1));
		string result = combination(process+substring, rest, count + 1);
		if (result < best_result)
			best_result = result;
	}

	return best_result;
}


int main()
{
	string str;
	cin >> str;

	for (int i = 0; i < 50; i++)
		best_result += 'z';
	combination("", str, 1);

	cout << best_result << endl;
}

