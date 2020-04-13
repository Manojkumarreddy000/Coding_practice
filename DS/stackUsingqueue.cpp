// implementation of stack using queue

#include<bits/stdc++.h>
#include<queue>

using namespace std;

class Stack{
private:
	queue<int> q1,q2;
	int current_size;
public:
	Stack(){
		current_size = 0;
	}

	void push(int x){
		current_size++;	
		q2.push(x);

		while(!q1.empty()){
			q2.push(q1.front());
			q1.pop();
		}

		queue<int> q = q1;
		q1 = q2;
		q2 = q;		
			
	}

	//int pop(){
	 void pop(){
		if(q1.empty()){
			cout<<"oh!!! the stack is empty";
			exit(0);
		}

		//int x = q1.front();
		q1.pop();
		current_size--;

	}


	int top(){
		if(q1.empty())
			return -1;
		return q1.front();

	}

	int size(){
		return  current_size;
	}

};


int main(){
		Stack s;
		s.push(1);
		s.push(2);
		s.push(3);
		
		cout<<"Current size of the stack: "<<s.size()<<endl;

		cout<<s.top()<<endl;
		s.pop();
		cout<<s.top()<<endl;
		s.pop();
		cout<<s.top()<<endl;
		s.pop();

		cout<<s.top()<<endl;
		s.pop();

	return 0;
}
