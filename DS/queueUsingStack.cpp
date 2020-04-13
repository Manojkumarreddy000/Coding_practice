// code for implementing queue using stack

#include<bits/stdc++.h>
#include<stack>

using namespace std;

class Queue{
private:
	stack<int> s1,s2;
public:
	void enQueue(int x){
		while(!s1.empty()){
			s2.push(s1.top());
			s1.pop();
		}
		s1.push(x);
		while(!s2.empty()){
			s1.push(s2.top());
			s2.pop();
		}
	}
	int deQueue(){
		if(s1.empty()){
			cout<<"oh!!! The Q is empty";
			exit(0);
		}
		
		int x = s1.top();
		s1.pop();
		return x;
	}
};

int main(){

	Queue q;
	q.enQueue(1);
	q.enQueue(2);
	q.enQueue(3);
	q.enQueue(4);
	q.enQueue(5);

	cout<<q.deQueue()<<endl;
	cout<<q.deQueue()<<endl;
	cout<<q.deQueue()<<endl;
	cout<<q.deQueue()<<endl;
	cout<<q.deQueue()<<endl;
	cout<<q.deQueue()<<endl;
	cout<<q.deQueue()<<endl;
	return 0;
}
