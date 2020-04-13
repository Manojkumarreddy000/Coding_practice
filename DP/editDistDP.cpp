// a naive recursive c++ program to find minimum number of 
//operetions to convert first string to second one using 
//		1.insert
//		2.remove
//		3.replace  operations only.

#include<bits/stdc++.h>
#include<string>

using namespace std;

int min( int a, int b, int c){
	return min(min(a, b),c);
}

int editDistance(string first, string second, int len1, int len2){
	int dp[len1+1][len2+1];

	for(int i=0,j;i<len1;i++)
		for(j=0;j<len2;j++){

		if(i == 0) // the first string is empty so insert all char from second string
			dp[i][j] = j;

		else if(j == 0)	//second string is empthy so remove all char from second string
			dp[i][j] = i;

		else if(first[i - 1] == second[j- 1])
			dp[i][j] = dp[i-1][j-1];

		else dp[i][j] =  1 + min( dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);
	}
	return dp[len1][len2];
}

int main(){

	string str1 = "sunday";
	string str2 = "saturday";

	cout<<editDistance(str1, str2,str1.length(), str2.length())<<endl;
	getchar();
	return 0;
}
