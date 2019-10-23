#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=10000;
bool visited[N][N];
int arr[N][N];
int num=1;
bool is_valid(int x,int y,int m,int n)
{
	if(x<m && x>=0 && y<n && y>=0)
	{
		if(!visited[m][n] && arr[x][y]==1) return true;
		else return false;
	}else return false;
}
void dfs(int i,int j,int m ,int n)
{
	if(!arr[i][j] || visited[i][j]) return;
	visited[i][j]=true;
	num++;
	if(is_valid(i+1,j,m,n)) dfs(i+1,j,m,n);
	if(is_valid(i-1,j,m,n)) dfs(i-1,j,m,n);
	if(is_valid(i,j-1,m,n)) dfs(i,j-1,m,n);
	if(is_valid(i,j+1,m,n)) dfs(i,j+1,m,n);

}
int main()
{
	int m,n,k;
	cin>>m>>n>>k;
	while(k--)
	{
		int a,b;
		cin>>a>>b;
		arr[a][b]=1;
	}
	memset(visited,false,sizeof(visited));
	int maxi=0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		if(!visited[i][j]){
			if(arr[i][j]==1)
			{
				num=0;
				dfs(i,j,m,n);
				maxi=max(maxi,num);
			}
		}
	}
	cout<<maxi<<endl;

}
