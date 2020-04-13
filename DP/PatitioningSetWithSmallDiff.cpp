// Given a set, we have to partition this set into two sets such that the sum of the differences between the set is minimum

#include<bits/stdc++.h>
#include<climits>
#include<cmath>
using namespace std;

int findMin(int arr[], int n){
	int sum = 0;
	int min= sum;
	for(int i=0;i<n;i++)
		sum+=arr[i];

	int dp[n+1][sum+1] = {0};

	for(int i=1;i<=n;i++){
		for(int j=0;j<=sum;j++){
			if(j==0)
				dp[i][j]=1;
			if( dp[i-1][j] == 1 || dp[i-1][j-arr[i-1]] == 1)
					dp[i][j] = 1;
		}
	}
	min = sum;
	for(int j=1;j<=sum;j++){
		if(dp[n][j] == 1){
			if(abs(sum - j*2) < min)
				min = abs(sum-j*2);
		}
	}

	return min;

}

int main(){

	int arr[] = {3, 1, 4, 2, 2, 1}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << "The minimum difference between two sets is "
         << findMin(arr, n); 
    return 0; 
}  
