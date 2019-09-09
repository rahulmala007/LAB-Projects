#include<bits/stdc++.h>
#define ll long long 
using namespace std; 
  

int comp(string a, string b) 
{ 
    
    string ab = a.append(b);
    string ba = b.append(a); 
    return ab.compare(ba) > 0 ? 1: 0; 
} 
  

void printString(vector<string> arr) 
{ 
  
    sort(arr.begin(), arr.end(), comp); 
  
    for (int i=0; i < arr.size() ; i++ ) 
        cout << arr[i]; 
} 
  

int main() 
{ 
    vector<string> arr; 
    ll n;
    cin>>n;
    while(n--)
    {
    	ll t;
    	cin>>t;
    	while(t--)
    	{
    		string x;
    		cin>>x;
    		arr.push_back(x);
    	}
    	printString(arr);
    	arr.clear();
    	cout<<endl;
    }
  
    
  
   return 0; 
} 