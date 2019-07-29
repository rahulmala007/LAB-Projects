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
  {
        if(i<y.length())
        {
            int num=(x[i]-'0')+(y[i]-'0')+cry;
            if(num>=10)
            {   cry=num/10;
                z.push_back((num-10));

            }
            else {
                cry=0;
                z.push_back(num);
            }
        }

        else{
            int n=(x[i]-'0')+cry;

            if(n>10)
            {
                cry=n/10;
                z.push_back((n-10));
            }
            else{
                cry=0;
                z.push_back(n);
            }

            if(i==l-1)
            {

            if(cry) z.push_back(cry);
            }


        }


  }


    reverse(z.begin(),z.end());
    for(int j=0;j<z.size();j++)
    {
        cout<<z[j];
    }



}
