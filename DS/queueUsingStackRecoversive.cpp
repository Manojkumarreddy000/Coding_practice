// more efficient way of implimenting queue using stacks

#include<bits/stdc++.h>
#include<stack>

using namespace std;

class Queue{
private:
	stack<int> s1;
public:
	void enqueue(int x){
		s1.push(x);
	}

	int dequeue(){
		if(s1.empty()){
			cout<<" Oh!!! the Q is empty";
			exit(0);
		}


		int x = s1.top();
		s1.pop();
		if(s1.empty())
			return x;
		
		int item = dequeue();

		s1.push(x);
		return item;

	}
};

int main() 
{ 
    Queue q; 
    q.enqueue(1); 
    q.enqueue(2); 
    q.enqueue(3); 
  
    cout << q.dequeue() << '\n'; 
    cout << q.dequeue() << '\n'; 
    cout << q.dequeue() << '\n'; 
    cout << q.dequeue() << '\n'; 
  
    return 0; 
} 
