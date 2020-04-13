#include<iostream>
#include<climits>
#include<stack>
using namespace std;

class MinStack {
    struct Node{
        int data;
        int min;
    };
    stack<struct Node> s;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        struct Node temp;
        temp.data = x;
        if(s.empty())
            temp.min = x;
        else
            temp.min = (x<this->getMin()? x : this->getMin());
        s.push(temp);
    }
    
    void pop() {
        if(!s.empty())
            s.pop();
    }
    
    int top() {
        if(!s.empty())
            return s.top().data;
        return INT_MAX;
    }
    
    int getMin() {
        if(s.empty())
            return INT_MAX;
        else
            return s.top().min;
    }
};

int main(){
	MinStack *obj = new MinStack();

	obj->push(-2);
	cout<<obj->getMin()<<endl;
	obj->push(0);
	cout<<obj->getMin()<<endl;
	obj->push(-3);
	cout<<obj->getMin()<<endl;

	return 0;
}
