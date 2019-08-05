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


string subtract(string x, string y)
{
	vector<int>c;
	int xl = x.size();
	int yl = y.size();
	int i = x.size() - 1, j = y.size() - 1, k = 0;
	int cry = 0, digit;
	int f = 0;
	while(i >= 0 && j >= 0)
	{
		digit = x[i] - y[j] - cry;
		if(digit < 0)
		{
			digit += 10;
			cry = 1;
		}
		else
		{
			cry = 0;
		}
		c[k++] = digit;
		i--;
		j--;
	}
	while(i >= 0)
	{
		digit = x[i] - '0' - cry;
		if(digit < 0)
		{
			digit += 10;
			cry = 1;
		}
		else
		{
			cry = 0;
		}
		c[k++] = digit;
		i--;
	}
	for(i = 0; i < k; i++)
	{
		if(c[i])
			f = 1;
	}
	j = 0;
	string d = "";
	if(f)
	{
		i = k-1;
		while(!c[i])
			i--;
		for(; i >= 0; i--)
		{
			d += (c[i] + '0');
		}
	}
	return d;

}


void divide(string a, string b)
{
	int xl = a.size(), yl = b.size();
	vector<int> quotient(xl + 1, 0);
	if(xl < yl)
	{
		cout << 0 <<endl<< a <<endl;
	}
	else if(xl == yl && a.compare(b) < 0)
	{
		cout << 0 << endl << a << endl;
	}
	else if(xl == yl && a.compare(b) == 0)
	{
		cout << 1 << endl<< 0 << endl;
	}
	else
	{
		while(1)
		{
			if(a.size() == 0)
			{
				break;
			}
			if(a.size() == b.size())
			{
				if(a.compare(b) < 0)
					break;
			}
			if(a.size() < b.size())
			{
				break;
			}
			string z = b;
			if(a.compare(b) >= 0)
			{
				z.append(a.size() - b.size(), '0');
				quotient[a.size() - b.size()]++;
				a = subtract(a, z);
			}
			else
			{
				z.append(a.size() - b.size() - 1, '0');
				quotient[a.size() - b.size() - 1]++;
				a = subtract(a, z);
			}
	;
			
		}
		for(int i = 0; i < xl + 1; i++)
		{
			if(quotient[i] > 9)
			{
				quotient[i+1] += quotient[i] / 10;
				quotient[i] = quotient[i] % 10;
			}
		}
			
		if(a.size())
		{
			int i = xl - 1;
			while(!quotient[i])
				i--;
			for(;i >= 0; i--)
				cout << quotient[i];
			cout << '\n';
			cout << a << '\n';
		}
		else
		{
			int i = xl - 1;
			while(!quotient[i])
				i--;
			for(;i >= 0; i--)
				cout << quotient[i];
			cout << '\n';
			cout << 0 << '\n';
		}
	}	
	
}




int main()
{
	int t;
	cin >>t;
	while(t--)
	{
		string a, b;
		int f = 0;
		cin >> a >>b;
		int i;
		for(int i = 0; i < a.size(); i++)
		{
			if(a[i] != '0')
			{
				f = 1;
				break;
			}
		}
		if(f)
			a = a.substr(i);
		else
			a = "0";
		f = 0;
		
		for(i = 0; i < b.size(); i++)
		{
			if(b[i] != '0')
			{
				f = 1;
				break;
			}
		}
		if(f)
			b = b.substr(i);
		else
			b = "0";
		divide(a, b);
		
	}
	return 0;
}

