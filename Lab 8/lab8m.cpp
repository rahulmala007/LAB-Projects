#include<bits/stdc++.h>
#define ll long long int
using namespace std;
long long int partition(double arr[], ll l, ll r, double k);
double findMedian(double arr[], long long int n)
{
sort(arr, arr+n);
return arr[n/2];
}
double MedElement(double arr[], ll l, ll r, ll k)
{
if (k > 0 && k <= r - l + 1)
{
ll n = r-l+1;
ll i; double median[(n+4)/5];
for (i=0; i<n/5; i++)
median[i] = findMedian(arr+l+i*5, 5);
if (i*5 < n)
{
median[i] = findMedian(arr+l+i*5, n%5);
i++;
}
double medOfMed = (i == 1)? median[i-1]:
MedElement(median, 0, i-1, i/2);
int pos = partition(arr, l, r, medOfMed);
if (pos-l == k-1)
return arr[pos];
if (pos-l > k-1)
return MedElement(arr, l, pos-1, k);
return MedElement(arr, pos+1, r, k-pos+l-1);
}
}
ll partition(double arr[], ll l, ll r, double x)
{
ll i;
for (i=l; i<r; i++)
if (arr[i] == x)
break;
swap(arr[i], arr[r]);
i = l;
for (ll j = l; j <= r - 1; j++)
{
if (arr[j] <= x)
{
swap(arr[i], arr[j]);
i++;
}
}
swap(arr[i], arr[r]);
return i;
}
int main()
{
ll t;
cin>>t;
while(t--)
{
ll k;
cin>>k;
double arr[k];
for(long long int i=0;i<k;i++)
{
long long int x,y;
cin>>x>>y;
double d = sqrt(x*x+y*y);
arr[i] = d;
}
cout<<MedElement(arr,0,k-1,(k+1)/2)<<endl;
}
}
