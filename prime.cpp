#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;

	if(n==2 || n==3) {
		cout<<"YES"<<endl;
		return 0;
	}
	
	for(int i=5;i<sqrt(n);i+=6)
	{
		if(n%i==0 || n%(i+2)==0) 
		{
			cout<<"YES"<<endl;
			return 0;
		}
	}

	cout<<"FALSE"<<endl;
}