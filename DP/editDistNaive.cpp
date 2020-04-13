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
	
	if(len1 == 0) // the first string is empty so insert all char from second string
		return len2;

	if(len2 == 0)	//second string is empthy so remove all char from second string
		return len1;

	if(first[len1 - 1] == second[len2 - 1])
		return editDistance(first,second,len1 - 1,len2 - 1);

	return 1 + min(editDistance(first,second,len1 - 1,len2 - 1),
			editDistance(first,second,len1,len2 - 1),
			editDistance(first,second,len1 - 1,len2)
		);
}

int main(){

	string str1 = "sunday";
	string str2 = "saturday";

	cout<<editDistance(str1, str2,str1.length(), str2.length())<<endl;
	getchar();
	return 0;
}
