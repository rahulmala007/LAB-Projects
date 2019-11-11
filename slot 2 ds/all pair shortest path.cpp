#include <bits/stdc++.h> 
using namespace std;   
#define I 100000
const int V=4;   
void printSolution(int dist[][V]);  
void floydWarshall (int graph[][V])  
{  
    int dist[V][V], i, j, k;  
    for (i = 0; i < V; i++)  
        for (j = 0; j < V; j++)  
            dist[i][j] = graph[i][j];  
  
    for (k = 0; k < V; k++)  
    { for (i = 0; i < V; i++)  
        {      for (j = 0; j < V; j++)  
            {   if (dist[i][k] + dist[k][j] < dist[i][j])  
                    dist[i][j] = dist[i][k] + dist[k][j];  
            }  
        }  
    }  
    printSolution(dist);  
}  
  
void printSolution(int dist[][V])  
{  

    for (int i = 0; i < V; i++)  
    {  
        for (int j = 0; j < V; j++)  
        {  
            if (dist[i][j] == I)  
                cout<<"I"<<" ";  
            else
                cout<<dist[i][j]<<" ";  
        }  
        cout<<endl;  
    }  
}  
   
int main()  
{  

    int graph[V][V] = { {0, 5, I, 10},  
                        {I, 0, 3, I},  
                        {I, I, 0, 1},  
                        {I, I, I, 0}  
                    };  
    floydWarshall(graph);  
    return 0;  
} 
