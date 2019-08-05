#include<bits/stdc++.h>
using namespace std;

string sum(string x, string y)  
{ 
    if (x.length() > y.length()) 
        swap(x, y); 
 
    string str = ""; 
    int n1 = x.length(), n2 = y.length(); 
    reverse(x.begin(), x.end()); 
    reverse(y.begin(), y.end()); 
  
    int cry = 0; 
    for (int i=0; i<n1; i++) 
    { 
        int sum = ((x[i]-'0')+(y[i]-'0')+cry); 
        str.push_back(sum%10 + '0'); 
        cry = sum/10; 
    } 
    for (int i=n1; i<n2; i++) 
    { 
        int sum = ((y[i]-'0')+cry); 
        str.push_back(sum%10 + '0'); 
        cry = sum/10; 
    } 
    if (cry) 
        str.push_back(cry+'0'); 
    reverse(str.begin(), str.end()); 
  
    return str; 
} 

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string x,y;
		cin>>x>>y;
		cout<<sum(x,y)<<endl;
	}
  


}
