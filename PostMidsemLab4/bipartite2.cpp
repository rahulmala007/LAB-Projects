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
bool visit(ll x,vector<vector<ll>> v, int val, vector<int>arr)
{
    for(ll i=0;i<v[x].size();i++)
    {
        if(arr[v[x][i]]==val)
        return false;
        else if(arr[v[x][i]]==-1)
        {
            arr[v[x][i]]=1-val;
            if(!visit(v[x][i],v,arr[v[x][i]],arr))
            return false;  
        }
    }
    return true;
}

int main()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>>v(n);
    ll x,y,w;
    vector<int>arr(n);
    for(ll i=0;i<n;i++)
    arr[i]=-1;
    forl(i,0,m)
    {
        cin>>x>>y>>w;
        if(w%2)
        {
            v[x-1].push_back(y-1);
            v[y-1].push_back(x-1);
        }
        else 
        {
            v.push_back({x-1,y-1});
            v[x-1].push_back(v.size()-1);
            v[y-1].push_back(v.size()-1);
            arr.push_back(-1);
        }
    }
    forl(i,0,v.si)
    {
        if(arr[i]==-1)
            if(!visit(i,v,0,arr))
            {
                cout<<"YES"<<endl;
                return 0;
            }
    }
    cout<<"NO"<<endl;
    return 0;

}

