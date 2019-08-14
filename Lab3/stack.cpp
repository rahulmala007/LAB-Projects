#include<bits/stdc++.h>
using namespace std;

bool isBalanced(string x)
{
	stack<char>s;
	long long int l=x.length();
	
	for(long long int i=0;i<l;i++)
	{
		if(x[i]=='(' || x[i]=='{' || x[i]=='[' || x[i]=='<') 
		{
			s.push(x[i]);
			
		}
		else if(x[i]==')' || x[i]=='}' || x[i]==']' || x[i]=='>'){
			if(s.empty()) return false;
			else{
				if(x[i]==')')
				{
					if(s.top()!='(') return false;
					else s.pop();
				}
				
				else if(x[i]=='}')
				{
					if(s.top()!='{') return false;
					else s.pop();
				}
				
				else if(x[i]==']')
				{
					if(s.top()!='[') return false;
					else s.pop();
				}
				
				else if(x[i]=='>')
				{
					if(s.top()!='<') return false;
					else s.pop();
				}
				else{
					if(s.top()!='|') return false;
					else s.pop();
				}
			}
		}
		else
		{	if(!s.empty())
			{
				if(s.top()!='|') 
			{
				s.push(x[i]);
				continue;
			}
			else 
			{
				if(s.empty()) return false;
				else{
					s.pop();
				}	
			}
			}else{
				s.push(x[i]);
			}
		
		}
	
	}
	if(s.empty()) return true;
	else return false;
}
int main()
{
	long long int t;
	cin>>t;
	while(t--)
	{
		string x;
		cin>>x;
		if(isBalanced(x)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}