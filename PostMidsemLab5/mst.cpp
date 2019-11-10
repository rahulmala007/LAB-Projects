#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define si size()
#define bk back()
#define popb pop_back()
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl "\n"
#define lb lower_bound
#define ub upper_bound
#define emp empty()
#define beg begin()
#define en end()
#define ump unordered_map
#define forl(i,a,n) for(int i=a;i<n;i++)
#define rfor(i,n,a) for(int i=n;i>=a;i--)
#define fore(i,a,n) for(int i=a;i<=n;i++)
#define len length()

using namespace std;
int findset(int p[], int x){
	if(x!=p[x]){
		p[x]=findset(p,p[x]);
	}
	return p[x];
}
void unionset(int p[],int r[],int a,int b){
	int x=findset(p,a);
	int y=findset(p,b);
	if(x!=y){
		if(r[x]<r[y]) swap(x,y);
		p[y]=x;
		if(r[x]==r[y]){
			r[x]++;
		}
	}
}
int main()
{
    int n,m;
    cin>>n>>m;
    ll N=1e9+7;
    int x,y,w;
    vector<pair<int,pair<int,int>>>vect;
    forl(i,0,m)
    {
        cin>>x>>y>>w;
        vect.pb({w,{x-1,y-1}});
    }
    sort(vect.beg,vect.en);
    int p[n],r[n];
    for(int i=0;i<n;i++)
    {
        p[i]=i;
        r[i]=0;
    }
    vector<int> v;
    rfor(i,m-1,0)
    {
        x=findset(p,vect[i].se.fi);
        y=findset(p,vect[i].se.se);
        if(x!=y)
        {
            v.push_back(i);
            unionset(p,r,vect[i].se.fi,vect[i].se.se);
        }
    }
   	ll s=1;
    forl(i,0,v.si)
    s=(s*vect[v[i]].fi)%N;
    cout<<s<<endl;
    return 0;
}
