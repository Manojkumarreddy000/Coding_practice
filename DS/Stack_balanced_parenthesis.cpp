// this program checks if the given parenthesis are in balanced form

#include<bits/stdc++.h>

using namespace std;

bool checkBalancedParenthesis(string str){

	stack<char> s;
	char x;

	for(int i=0;i<str.length();i++){
		if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
			s.push(str[i]);
			continue;
		}

		
		if(s.empty())
			return false;
	
		switch(str[i]){
			case ')':	x = s.top();
						s.pop();
					if(x == '[' || x == '{')
						return false;
					break;
			
			case ']':	x = s.top();	
						s.pop();
					if(x == '(' || x == '{')
						return false;
					break;

			case '}':	x = s.top();	
						s.pop();
					if(x == '[' || x == '(')
						return false;
					break;
		}
	}

	return (s.empty());

}

int main() 
{ 
    string expr = "{()}[]"; 
  
    if (checkBalancedParenthesis(expr)) 
        cout << "Balanced"; 
    else
        cout << "Not Balanced"; 
    return 0; 
}

	
