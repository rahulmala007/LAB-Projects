#include<bits/stdc++.h>
using namespace std;

void prime(int n)
{

	if (n <= 1){
		cout<<"NO"<<endl;
		return;
	}
    if (n==2 || n==3){
    	cout<<"YES"<<endl;
    	return;
	} 

    if (n%2 == 0 || n%3 == 0){
    	cout<<"N0"<<endl;
    	return;
	}
  
    for (int i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
          {
          	cout<<"NO"<<endl;
          	return;
		  }
  
    cout<<"YES"<<endl;
    
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		prime(n);
	}
}



