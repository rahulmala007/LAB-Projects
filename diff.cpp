#include<bits/stdc++.h>
using namespace std;

int main()
{
	string x;
  string y;
  vector<int>z;
  string s;

  cin>>x;
  cin>>y;
    if(y.length()>x.length())
    {
        s=x;
        y=s;
        x=y;
    }


  reverse(x.begin(),x.end());
  reverse(y.begin(),y.end());

  int l=x.length();
    int cry=0;
    for(int i=0;i<l;i++)
    {	int a=(x[i]-'0')
    	int b=(y[i]-'0')
    	if(a>=b)
    	{
    		z.push_back(a-b);
    	}
    	else{

    		if(i<y.length())
    		{	for(int j=i+1;j<l;j++)
    			{	int c=x[j]-'0'
    				if(c) 
    				{
    					c--;
    					char nu=c;
    					x[j]=nu;
    					break;

    				}
    			}
  
    				z.push_back(a-b+10)
    		}
    		else{

    			z.push_back(a);
    		}
    	} 

    }

    reverse(z.begin(),z.end());
    for(int j=0;j<z.size();j++)
    {
        cout<<z[j];
    }






}
