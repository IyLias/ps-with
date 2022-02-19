#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define MAXLEN	1001

using namespace std;

int dp[MAXLEN][MAXLEN];

int main(){

 string s1,s2;
 getline(cin,s1);
 getline(cin,s2);

 string lcs;

 for(int i=0;i<s1.length();i++){
    for(int j=0;j<s2.length();j++){
	if(s1.at(i) == s2.at(j))
	   dp[i+1][j+1] = dp[i][j] + 1;
	else
	   dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
    }

 }
 

 printf("%d\n",dp[s1.length()][s2.length()]);

 return 0;
}
