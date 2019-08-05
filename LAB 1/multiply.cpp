#include<bits/stdc++.h>
using namespace std; 

string sum(string x, string y)  // sum function as in prob 1
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

string OneMultiply(string a,char ch,int l){ 
	int x= ch-'0';
	string str="0";
	int cry=0;
	for(int i=l-1;i>=0;i--){
		int temp=(a[i]-'0')*x + cry;
		a[i]=temp%10 + '0';
		cry=temp/10;
	}
	
	str[0] = cry+'0';

	if(!cry){
		return a;
	}else{
		return str.append(a);
	}
}

string multiply(string a,string b){
	long long int al=a.length();
	long long int bl=b.length();
	string result="";
	long long int k=0;
	string zero="0";
	for(long long int i=al-1;i>=0;i--){
		string str=OneMultiply(b,a[i],bl);
		for(long long int z=0;z<k;z++){
			str.append(zero);
		}
		k++;
		result=sum(str,result);
	}
	return result;
}


int main(){
	int t;
	cin>>t;
	while(t--){
		string x,y;
		cin>>x>>y;
		cout<<multiply(x,y)<<endl;
	}
	return 0;
}
