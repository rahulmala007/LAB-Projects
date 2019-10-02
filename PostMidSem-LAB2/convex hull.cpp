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
#define forl(i,a,n) for(int i=a;i<n;i++)
#define rfor(i,n,a) for(int i=n;i>=a;i--)
#define fore(i,a,n) for(int i=a;i<=n;i++)
struct point {    
   int x, y;
};
point p0;
point secTop(stack<point>&st) {
	point top=st.top();
	st.pop();
	point sec=st.top();
	st.push(top);
	return sec;
}


int Dist(point a, point b) {
   return pow((a.x-b.x),2)+pow((a.y-b.y),2);
}


int orient(point a, point b, point c) {
   int val = (b.y-a.y)*(c.x-b.x)-(b.x-a.x)*(c.y-b.y);
   if(!val)return 0;    
   else if(val < 0) return 2;    
	else return 1;    
}


int comp(const void *point1, const void*point2) {
   point *p1 = (point*)point1;
   point *p2 = (point*)point2;
   int dir = orient(p0, *p1, *p2);
   if(dir == 0)
      return (Dist(p0, *p2) >= Dist(p0, *p1))?-1 : 1;
   return (dir==2)? -1 : 1;
}


vector<point>ConvexHull(point points[], int n) {
   vector<point> Pts;
   int miny = points[0].y, min = 0;
   forl(i,1,n)
    {
      int y = points[i].y;
      
      if((y < miny) || (miny == y) && points[i].x < points[min].x) {
         miny = points[i].y;
         min = i;
      }
   }
   swap(points[0], points[min]);    
   p0 = points[0];
   qsort(&points[1], n-1, sizeof(point), comp);    
   int arrSize = 1;    
   forl(i,1,n) 
   {
      while(i<n-1 && orient(p0, points[i], points[i+1]) == 0)
         i++;
         points[arrSize] = points[i];
         arrSize++;
   }
   if(arrSize < 3)
      return Pts;   
      
      stack<point> st;
      st.push(points[0]); st.push(points[1]); st.push(points[2]);
   forl(i,3,arrSize) { 
      while(orient(secTop(st), st.top(), points[i]) != 2)
         st.pop();   
         st.push(points[i]);
   }
   while(!st.empty()) {
      Pts.pb(st.top());    
      st.pop();
   }
}
int main() {
   int t;
   cin>>t;
   vector<point>v;
   point points[t];
   forl(i,0,t)
   		cin>>points[i].x>>points[i].y;
   v=ConvexHull(points, t);
   int test=0;
   forl(i,0,v.si)
   {
   		if(v[i].x<v[test].x) test=i;
   		else if(v[i].x==v[test].x && v[i].y<v[test].y) test=i;
   }
   cout<<v.si<<endl;
	forl(i,0,v.si)
   		cout<<v[(i+test)%v.si].x<<" "<<v[(i+test)%v.si].y<<endl;
}
