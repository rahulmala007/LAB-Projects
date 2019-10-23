#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=10000;
bool visited[N][N];
int arr[N][N];
int num=1;
bool is_valid(int x,int y,int m,int n,int c)
{
	if(x<m && x>=0 && y<n && y>=0)
	{
		if(!visited[m][n] && arr[x][y]==c) return true;
		else return false;
	}else return false;
}
void dfs(int i,int j,int m,int n,int col)
{
	if(arr[i][j]!=col || visited[i][j])return;
	visited[i][j]=true;
	num++;
	if(is_valid(i+1,j,m,n,col)) dfs(i+1,j,m,n,col);
	if(is_valid(i-1,j,m,n,col)) dfs(i-1,j,m,n,col);
	if(is_valid(i,j-1,m,n,col)) dfs(i,j-1,m,n,col);
	if(is_valid(i,j+1,m,n,col)) dfs(i,j+1,m,n,col);

}
int main()
{
	int m,n,c;
	cin>>m>>n>>c;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>arr[i][j];
		}
	}
	memset(visited,false,sizeof(visited));
	int maxi=0;
	int maxcol=0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
        if(!visited[i][j]){
			int col=arr[i][j];
			num=0;
			dfs(i,j,m,n,col);
			if(num>=maxi) maxcol=col;
			maxi=max(maxi,num);
			
		}
	}
	cout<<maxi<<" "<<maxcol<<endl;

}
