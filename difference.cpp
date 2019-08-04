#include<bits/stdc++.h>
using namespace std;

bool large(string x,string y)
{
	if(x.length()>y.length()) return true;
	for(int i=0;i<x.length();i++)
	{
		if(x[i]<y[i]) return false;
		if(x[i]>y[i]) return true;
	}
	return true;
}

void diff(string x,string y)
{
	vector<int>z;
  	string s;
	int check=0;
    if(!large(x,y))
    {	check=1;
        swap(x,y);
    }
	if(x==y)
	{
		cout<<"0"<<endl;
		return;
	}

  reverse(x.begin(),x.end());
  reverse(y.begin(),y.end());

  int l=x.length();
    int cry=0;
    for(int i=0;i<l;i++)
    {	int a=(x[i]-'0');
    	int b=0;
    	if(i<y.length()) b=(y[i]-'0');
    	
		if(a>=b)
    	{
    		z.push_back(a-b);
    	}
    	else
		{
				for(int j=i+1;j<l;j++)
    			{	int c=x[j]-'0';
    				if(c) 
    				{
    					c--;
    					char nu=c+'0';
    					x[j]=nu;
    					break;

    				}
    			}
  
    				z.push_back(a-b+10);
    		}
    	} 


    reverse(z.begin(),z.end());
    if(check) cout<<"-";
    for(int j=0;j<z.size();j++)
    {	if(z[j])
        cout<<z[j];
    }

}

int main()
{
	
  	int t;
  	cin>>t;
  	while(t--)
  	{
  		string x,y;
  		cin>>x>>y;
  		diff(x,y);
  		
	  }





}
