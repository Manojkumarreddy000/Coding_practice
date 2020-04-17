// this program is to solve the 8 queen problems
// when we have to place * queens on a chess board such that no queen would kill each other


#include<bits/stdc++.h>

using namespace std;

#define N 30
int number_of_solutions;
int see_solutions;

// Function to print the solution

void printSolution(int board[N][N]){
	static int k = 1;
	cout<<k++<<"\n";

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<" "<<board[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
}

// to check the queen which is place in a new colomn

bool isSafe(int board[N][N], int row, int col){
	int i,j;
	for(i=0;i<col;i++) // checking the elements in the left
		if(board[row][i])
				return false;

	for(i=row,j=col;i>=0 and j>=0 ;i--,j--) // checking the elements in upper diagonal on the left
		if(board[i][j])
				return false;


	for(i=row,j=col;i<N and j>=0 ;i++,j--) // checking the elements in lower diagonal on the left
		if(board[i][j])
				return false;

	return true;
}

// recursive function to solve the problem

bool solveNQUtil(int board[N][N], int col){
	if(col==N){
		if(see_solutions == 1)
			printSolution(board);
		number_of_solutions++;
		return true;
	}
	//cout<<number_of_solutions<<endl;

	bool res = false;
	for( int i=0;i<N;i++){
		if(isSafe(board,i,col)){
			board[i][col] =1;

			res = solveNQUtil(board,col+1)||res;

			board[i][col] =0;
		}
	}
	return res;

}

void solveNQU(){
	int board[N][N];
	number_of_solutions = 0;
	memset(board,0,sizeof(board));

	if(solveNQUtil(board,0) == false){
		cout<<"solution does not exit";
		return;
	}

	cout<<"Number of possible solutions are/is:"<<number_of_solutions<<endl;
	return;
}

int main(){
		see_solutions = 2;
		cout<<"\nPress 1:if u want to see all the possible solutions";
		cout<<"\nPress 0:if u want to ignore seeing the possible solutions";
	
		cin>>see_solutions;

	solveNQU();
}
